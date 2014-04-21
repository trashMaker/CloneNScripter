#include "Novel.cpp"

int _tmain(){
	using namespace makeCto;
#if UNICODE
	wcout.imbue(locale("Japanese"));
	Novel<basic_string<wchar_t>> novel(_T("../Conversation/ScenarioUTF-8.txt"));
#else if
	Novel<basic_string<char>> novel(_T("../Conversation/Scenario.txt"));
#endif
	try{
		novel.readFile();
	}
	catch (string error){
		cout << error<< endl;
	}

	int max = novel.getManyLine();

	for (int i = 0; i < max; i++){
		novel.draw(i);
	}

	return 0;
}
