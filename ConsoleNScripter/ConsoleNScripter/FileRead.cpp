/**********************************************************
*
*		FileRead
*
*								2014/4/21  煩悩Cト
***********************************************************/
#ifndef __FILEREAD_CPP__
#define __FILEREAD_CPP__
#include <fstream>
#include "Common.h"
#include "Novel.h"

/**
@file ファイル
ファイルの読み込み
テキストファイルから一列事に取得したデータとその列の数を持っている
*/
namespace makeCto{

	using namespace std;

	template <class T>
	class FileRead{
	private:
		PCTSTR SCENARIO;//File name
		T str[STRNUM];//File data in
		int ManyLine;//File data number
	public:
		FileRead();//Constructor
		FileRead(PCTSTR);//Constructor with argument
		~FileRead();//Destructor

		void readFile();//read file
		void readFileUTF_8();//read file

		void setManyLine(int index);//set an argument to ManyLine 
		int getManyLine();//get ManyLine

		void setStr(T argumentStr, int index);//set strIndex the type string str

		T getStr(int index);//type string return str[index]
	};
}

namespace makeCto{
	/**
		コンストラクタ Constructor  2014/4/21 MakeCト
	*/
	template<class T>
	FileRead<T>::FileRead(){
#if UNICODE
		SCENARIO(_T("../Conversation/ScenarioUTF-8.txt"));
#else if
		SCENARIO(_T("../Conversation/Scenario.txt"));
#endif
		
		ManyLine = 0;
	}
	/**
		引数付きコンストラクタ Constructor with argument 2014/4/21 MakeCト
		@param	scenario	[out] set the read text file in this argument
	*/
	template<class T>
	FileRead<T>::FileRead(PCTSTR scenario) : SCENARIO(scenario){

	}
	/**
		デストラクタ Destructor 2014/4/21 MakeCト
	*/
	template<class T>
	FileRead<T>::~FileRead(){

	}
	/**
		ファイル読み込み　File read 2014/4/21 MakeCト
	*/
	template<class T>
	void FileRead<T>::readFile(){

#if UNICODE
		basic_string<wchar_t> str;
		FILE *fp = _tfopen(SCENARIO, _T("r,ccs=UTF-8"));
		if (fp == NULL){
			throw "readFile:not open";
		}
		wifstream ifs(fp);

		int strIndex = 0;

		while (getline(ifs,str)){
			setStr(str, strIndex);
			strIndex++;
		}
		fclose(fp);
#else if
		TCHAR temp[STRNUM] = "";
		ifstream fin(SCENARIO);
		if(!fin){
			throw "readFile:not open";
		}
		int strIndex = 0;

		while (!fin.eof()){
			fin.getline(temp, STRNUM);
			//setStr(temp, strIndex);
			str[strIndex] = temp;
			strIndex++;
		}
#endif
		setManyLine(strIndex); 
	}
	//template<class T>
	//void FileRead<T>::readFileUTF_8(){
	//	
	//}
	/**
		ManyLineの値を返す 2014/4/21 MakeCト
		@attention	please use it after setting the str,this function
		@return		return ManyLine
	*/
	template<class T>
	void FileRead<T>::setManyLine(int index){
		//check overrun
		if (0 > index || index >= STRNUM){
			throw "setManyLine:access overrun.";
		}
		ManyLine = index;
	}
	/**
		ManyLineの値を返す 2014/4/21 MakeCト
		@attention	please use it after setting the str,this function
		@return		return ManyLine
	*/
	template<class T>
	int FileRead<T>::getManyLine(){
		return ManyLine;
	}
	/**
		strのindexにargumentStr設定 2014/4/21 MakeCト
		@param[out] argumentStr	set the position of the index of str
		@param[out] index		set index
		@attention	please use it after setting the str,this function
	*/
	template<class T>
	void FileRead<T>::setStr(T argumentStr, int index){
		//check overrun
		if (0 > index || index >= STRNUM){
			throw "setStr:access overrun.";
		}
		str[index] = argumentStr;
	}
	/**
		strにindexを設定してそれを返す 2014/4/21 MakeCト
		@param[out] index	set str index
		@attention	please use it after setting the str,this function
		@return		type string return
	*/
	template<class T>
	T FileRead<T>::getStr(int index){
		//check overrun
		if (0 > index || index >= STRNUM){
			throw "getStr:access overrun.";
		}
		return str[index];
	}
}

#endif __FILEREAD_H__//省略可能