#include "FileRead.h"
#include "Novel.h"

namespace makeCto{
	/**
		�R���X�g���N�^ Constructor  2014/4/21 MakeC�g
	*/
	FileRead::FileRead() :SCENARIO("../Conversation/Scenario.txt"){
		ManyLine = 0;
	}
	/**
		�����t���R���X�g���N�^ Constructor with argument 2014/4/21 MakeC�g
		@param	scenario	[out] set the read text file in this argument
	*/
	FileRead::FileRead(const char* scenario) : SCENARIO(scenario){

	}
	/**
		�f�X�g���N�^ Destructor 2014/4/21 MakeC�g
	*/
	FileRead::~FileRead(){

	}
	/**
		�t�@�C���ǂݍ��݁@File read 2014/4/21 MakeC�g
	*/
	void FileRead::readFile(){

		ifstream fin(SCENARIO);
		//temporary data
		char temp[STRNUM] = "";
		int strIndex = 0;
		
		while (!fin.eof()){
			fin.getline(temp, STRNUM);
			//setStr(temp, strIndex);
			str[strIndex] = temp;
			strIndex++;
		}
		
		setManyLine(strIndex); 
	}

	void FileRead::readFile(int){
		//FILE *fp = _tfopen(SCENARIO, _T("r,ccs=UTF-8"));
	}
	/**
		ManyLine�̒l��Ԃ� 2014/4/21 MakeC�g
		@attention	please use it after setting the str,this function
		@return		return ManyLine
	*/
	void FileRead::setManyLine(int index){
		//check overrun
		if (0 > index || index >= STRNUM){
			throw "setManyLine:access overrun.";
		}
		ManyLine = index;
	}
	/**
		ManyLine�̒l��Ԃ� 2014/4/21 MakeC�g
		@attention	please use it after setting the str,this function
		@return		return ManyLine
	*/
	int FileRead::getManyLine(){
		return ManyLine;
	}
	/**
		str��index��argumentStr�ݒ� 2014/4/21 MakeC�g
		@param[out] argumentStr	set the position of the index of str
		@param[out] index		set index
		@attention	please use it after setting the str,this function
	*/
	void FileRead::setStr(string argumentStr, int index){
		//check overrun
		if (0 > index || index >= STRNUM){
			throw "setStr:access overrun.";
		}
		str[index] = argumentStr;
	}
	/**
		str��index��ݒ肵�Ă����Ԃ� 2014/4/21 MakeC�g
		@param[out] index	set str index
		@attention	please use it after setting the str,this function
		@return		type string return
	*/
	string FileRead::getStr(int index){
		//check overrun
		if (0 > index || index >= STRNUM){
			throw "getStr:access overrun.";
		}
		return str[index];
	}
}