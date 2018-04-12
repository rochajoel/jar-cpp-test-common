/*
 * FileCleaner.hpp
 *
 *  Created on: 12/04/2018
 *      Author: withus
 */

#ifndef SRC_FILECLEANER_HPP_
#define SRC_FILECLEANER_HPP_

#include <string>

namespace TestUnitCommon
{
	using namespace std;

	class FileCleaner
	{
		string filePath;
	public:
		FileCleaner(string filePath) : filePath(filePath)	{ remove(filePath.c_str()); }
		~FileCleaner()										{ remove(filePath.c_str()); }
	};
}

#endif /* SRC_FILECLEANER_HPP_ */
