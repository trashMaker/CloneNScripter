#include "Novel.h"

int _tmain(){
	using namespace makeCto;
#if UNICODE
	wcout.imbue(locale("Japanese"));
#endif
	Novel novel;
	novel.readFile();

	int max = novel.getManyLines();

	for (int i = 0; i < max; i++){
		novel.draw(i);
	}

	return 0;
}
