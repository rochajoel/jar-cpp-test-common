
#ifndef JAR_TTYEMULATOR_HPP_
#define JAR_TTYEMULATOR_HPP_

#include <string>

#include <unistd.h>
#include <fcntl.h>

namespace TestUnitCommon
{
	using namespace std;

	class TTYEmulator
	{
		int m_ttyFD;

	public:
		TTYEmulator()
		{
			m_ttyFD = posix_openpt(O_RDWR);

			unlockpt(m_ttyFD);
		}
		virtual ~TTYEmulator()
		{
			close(m_ttyFD);
		}

		void send(const string data)
		{
			if (write(m_ttyFD, &data[0], data.size()) == -1)
				fprintf(stderr, "Could not write on tty!\n");
		}

		char* getSlaveTTYName()
		{
			return ptsname(m_ttyFD);
		}

		string readLine()
		{
			std::string line(2048, 0);
			int readSize = -1;

			if ((readSize = read(m_ttyFD, &line[0], line.size())) == -1)
				throw ios_base::failure("Could not read from tty!\n");

			return line.substr(0, readSize);
		}
	};
}

#endif /* JAR_TTYEMULATOR_HPP_ */
