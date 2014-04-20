/**********************************************************
*
*		FileRead
*
*								2014/4/21  煩悩Cト
***********************************************************/
#ifndef __FILEREAD_H__
#define __FILEREAD_H__

/**
	@file ファイル
	ファイルの読み込み
	テキストファイルから一列事に取得したデータとその列の数を持っている
*/

#include <fstream>
#include "Common.h"

namespace makeCto{

	using namespace std;

	class FileRead{
	private:
		const char* SCENARIO;//File name
		string str[STRNUM];//File data in
		int ManyLine;//File data number
	public:
		FileRead();//Constructor
		FileRead(const char*);//Constructor with argument
		~FileRead();//Destructor

		void readFile();//read file
		void readFile(int);//read file

		void setManyLine(int index);//set an argument to ManyLine 
		int getManyLine();//get ManyLine
		
		void setStr(string argumentStr, int index);//set strIndex the type string str
		string getStr(int index);//type string return str[index]
	};
}

#endif __FILEREAD_H__//省略可能

