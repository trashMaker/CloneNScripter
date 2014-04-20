/**********************************************************
*
*		FileRead
*
*								2014/4/21  �ϔYC�g
***********************************************************/
#ifndef __FILEREAD_H__
#define __FILEREAD_H__

/**
	@file �t�@�C��
	�t�@�C���̓ǂݍ���
	�e�L�X�g�t�@�C�������񎖂Ɏ擾�����f�[�^�Ƃ��̗�̐��������Ă���
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

#endif __FILEREAD_H__//�ȗ��\

