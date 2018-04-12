
#ifndef JAR_PROBE_HPP_
#define JAR_PROBE_HPP_

#include <mutex>
#include <condition_variable>
#include <chrono>

namespace TestUnitCommon
{
	using namespace std;
	using namespace std::chrono;

	template<typename T>
	class CProbe
	{
	protected:
		mutex					m_mutex;
		condition_variable		m_condition;
		T*						m_data;

	public:
		CProbe() : m_data(nullptr) {}
		~CProbe() { delete m_data; }

		void pushData(T* data)
		{
			unique_lock<mutex> lock(m_mutex);

			m_condition.wait(lock, [&] { return m_data == nullptr; });

			m_data = data;
			m_condition.notify_all();
		}

		T* pullData()
		{
			unique_lock<mutex> lock(m_mutex);

			m_condition.wait(lock, [&] { return m_data != nullptr; });

			{
				T* payload = m_data;

				m_data = nullptr;
				m_condition.notify_all();

				return payload;
			}
		}
		T* pullData(seconds numberOfSeconds)
		{
			unique_lock<mutex> lock(m_mutex);

			m_condition.wait_for(lock, numberOfSeconds, [&] { return m_data != nullptr; });

			{
				T* payload = m_data;

				m_data = nullptr;
				m_condition.notify_all();

				return payload;
			}
		}
	};
}

#endif /* JAR_PROBE_HPP_ */
