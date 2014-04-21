#ifndef __NOVEL_CPP__
#define __NOVEL_CPP__

#include "Common.h"
#include "FileRead.cpp"

namespace makeCto{

	using namespace std;
	template<class T>
	class Novel{
	private:
#if UNICODE
		FileRead<basic_string<wchar_t>>* readNovelText;
#else if
		FileRead<basic_string<char>>* readNovelText;
#endif
	public:
		Novel();
		Novel(PCTSTR);
		~Novel();

		T getConversation(int index);
		int getManyLine();

		void readFile();

		void draw(int index);
	};
}

namespace makeCto{
	template<class T>
	Novel<T>::Novel(){
#if UNICODE
		readNovelText = new FileRead<basic_string<wchar_t>>(_T("../Conversation/ScenarioUTF-8.txt"));
#else if
		readNovelText = new FileRead<basic_string<char>>(_T("../Conversation/Scenario.txt"));
#endif
	}
	template<class T>
	Novel<T>::Novel(PCTSTR SCENARIO){
#if UNICODE
		readNovelText = new FileRead<basic_string<wchar_t>>(SCENARIO);
#else if
		readNovelText = new FileRead<basic_string<char>>(SCENARIO);
#endif
		
	}
	template<class T>
	Novel<T>::~Novel(){
		delete readNovelText;
	}
	template<class T>
	T Novel<T>::getConversation(int index){
		return readNovelText->getStr(index);
	}
	template<class T>
	void Novel<T>::draw(int index){
#if UNICODE
		wcout << getConversation(index) << endl;
#else if
		cout << getConversation(index) << endl;
#endif
	}
	template<class T>
	int Novel<T>::getManyLine(){
		return readNovelText->getManyLine();
	}
	template<class T>
	void Novel<T>::readFile(){

		readNovelText->readFile();
	}
}

#endif __NOVEL_CPP__//è»ó™â¬î\