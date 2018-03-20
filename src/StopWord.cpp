#include "StopWord.h"



StopWord::StopWord()
{
}

StopWord::StopWord(ifstream & is)
{
		string text;
		while (getline(is, text))
		{
				istringstream line(text);
				string word;
				while (line >> word)
						word_list.insert(word);
		}
}


StopWord::~StopWord()
{
}


bool StopWord::word_query(string word)
{
		if (word_list.find(word) == word_list.end())
				return false;
		else
				return true;
}
