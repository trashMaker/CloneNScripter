#ifndef __NOVEL_H__
#define __NOVEL_H__

#include "Common.h"
#include "FileRead.h"

namespace makeCto{

	using namespace std;

	class Novel{
	private:
		FileRead readNovelText;
	public:
		Novel();
		~Novel();

		string getConversation(int index);
		int getManyLines();

		void readFile();
		
		void draw(int index);
	};
}

#endif __NOVEL_H__//È—ª‰Â”\