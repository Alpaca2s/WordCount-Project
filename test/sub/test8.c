string line;
bool lineflag = true;
unsigned codeLine = 0;
unsigned emptyLine = 0;
unsigned commentLine = 0;
while (getline(ifstrm, line))
{
		unsigned n = 0;
		if (lineflag)
		{
				if ((line.find('/') != string::npos) && (line[line.find('/') + 1] == '/'))
				{
						line = line.substr(0, line.find('/'));
						istringstream text(line);
						string word;
						while (text >> word)
						{
								n = n + word.size();
						}
						if (n > 1)
						{
								++codeLine;
						}
						else
						{
								++commentLine;
						}
				}
				else if ((line.find('/') != string::npos) && (line[line.find('/') + 1] == '*'))
				{
						if (line.rfind('/') == line.find('/'))
								lineflag = false;
						line = line.substr(0, line.find('/'));
						istringstream text(line);
						string word;
						while (text >> word)
						{
								n = n + word.size();
						}
						if (n > 1)
						{
								++codeLine;
						}
						else
						{
								++commentLine;
						}
				}
				else
				{
						istringstream text(line);
						string word;
						while (text >> word)
						{
								n = n + word.size();
						}
						if (n > 1)
						{
								++codeLine;
						}
						else
						{
								++emptyLine;
						}
				}
		}
		else
		{
				if (line.find("*/") != string::npos)
				{
						lineflag = true;
						line = line.substr(line.find("*/") + 2, line.size() - line.find("*/") - 3);
						istringstream text(line);
						string word;
						while (text >> word)
						{
								n = n + word.size();
						}
						if (n > 1)
						{
								++codeLine;
						}
						else
						{
								++commentLine;
						}
				}
				else
				{
						++commentLine;
				}
		}
}
ifstrm.clear();
ifstrm.seekg(0, fstream::beg);