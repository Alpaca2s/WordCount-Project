#pragma once
#include <set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
class StopWord
{
public:
		StopWord();
		StopWord(ifstream &is);
		~StopWord();
private:
		set<string>word_list;
public:
		bool word_query(string word);
};