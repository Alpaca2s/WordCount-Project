#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

#define CF 0
#define WF 1
#define LF 2
#define SF 3
#define AF 4

int main(int argc, char *argv[])
{
		if (argc <= 2)
		{
				cerr << "请输入参数参数！" << endl;
				return 0;
		}

		bool flag[] = { false,false,false,false,false };
		regex ifname("[[:alnum:]]+\\.c$", regex::icase);
		regex ofname("[[:alnum:]]+\\.txt$", regex::icase);
		regex sfname("[[:alnum:]]+\\.txt$", regex::icase);
		string infile;
		string outfile;
		string stopfile;
		ifstream ifstrm;
		ofstream ofstrm;

		for (auto p = 1; p != argc; ++p)
		{
				if (*argv[p] == '-')
				{
						switch (*(argv[p] + 1))
						{
						case 99:				//-c参数
								flag[CF] = true;
								break;
						case 119:				//-w参数
								flag[WF] = true;
								break;
						case 108:				//-l参数
								flag[LF] = true;
								break;
						case 111:				//-o参数
								outfile = argv[++p];
								break;
						case 115:				//-s参数
								flag[SF] = true;
								break;
						case 97:				//-a参数
								flag[AF] = true;
								break;
						case 101:				//-e参数
								stopfile = argv[++p];
								break;
						case 120:				//-x参数
								cout << "不支持此功能！" << endl;
								return 0;
						default:
								cerr << "错误参数！" << endl;
								return 0;
						}
				}
				else
						infile = argv[p];
		}

		if (!regex_search(infile,ifname))
		{
				cerr << "缺少输入文件！" << endl;
				return 0;
		}
		ifstrm.open(infile);

		if (outfile.empty())
				outfile = "result.txt";
		else if (!regex_search(outfile, ofname))
		{
				cerr << "缺少输出文件" << endl;
				return 0;
		}
		ofstrm.open(outfile, ofstream::app);

		if (ifstrm.is_open())
		{
				if (ofstrm.is_open())
				{
						if (flag[CF])
						{
								char c;
								unsigned int charNum = 0;
								ifstrm >> noskipws;
								while (ifstrm >> c)
										++charNum;
								ifstrm >> skipws;
								ofstrm << infile << "，字符数：" << charNum << endl;
								ifstrm.clear();
								ifstrm.seekg(0, fstream::beg);
						}
						if (flag[WF])
						{
								string words;
								unsigned int wordNum = 0;
								while (ifstrm >> words)
								{
										++wordNum;
										for (auto it = words.begin() + 1; it < words.end() - 1; ++it)
												if (*it == 44)
														++wordNum;
								}
								ofstrm << infile << "，单词数：" << wordNum << endl;
								ifstrm.clear();
								ifstrm.seekg(0, fstream::beg);
						}
						if (flag[LF])
						{
								string line;
								unsigned int lineNum = 0;
								while (getline(ifstrm, line))
										++lineNum;
								ofstrm << infile << "，行数：" << lineNum << endl;
								ifstrm.clear();
								ifstrm.seekg(0, fstream::beg);
						}

						ofstrm << endl;
				}
				else
				{
						cerr << "输出文件打开失败！" << endl;
						return 0;
				}
		}
		else
		{
				cerr << "输入文件打开失败！" << endl;
				return 0;
		}

		cout << "运行成功，结果保存在：" << outfile << endl;
		return 0;
}