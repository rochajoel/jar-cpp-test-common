
#ifndef JAR_FILECLEANER_HPP_
#define JAR_FILECLEANER_HPP_

#include <string>

namespace TestUnitCommon
{
	using namespace std;

	class FileCleaner
	{
		string filePath;
	public:
		FileCleaner(string filePath) : filePath(filePath)	{ remove(filePath.c_str()); }
		~FileCleaner()						{ remove(filePath.c_str()); }
	};
}

#endif /* JAR_FILECLEANER_HPP_ */
