#include "Novel.h"
namespace makeCto{
	Novel::Novel(){

	}

	Novel::~Novel(){

	}


	string Novel::getConversation(int index){
		return readNovelText.getStr(index);
	}
	
	void Novel::draw(int index){
		cout << getConversation(index) << endl;
	}
	int Novel::getManyLines(){
		return readNovelText.getManyLine();
	}
	void Novel::readFile(){

		readNovelText.readFile();
	}
}