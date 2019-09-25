#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>


using namespace std;

//bool check_key(unordered_map<char, char> m, char key)
//{
//	unordered_map<char, char>::const_iterator got = m.find(key);
//	if (got == m.end)
//		return false;
//	else
//		return true;
//}

int main()
{
	string line;
	char inCharArr[43] = { '1','2','3','4','5','6','7','8','9','0','-','=',
						'W','E','R','T','Y','U','I','O','P','[',']','\\',
						'S','D','F','G','H','J','K','L',';','\'',
						'X','C','V','B','N','M',',','.','/' };
	char shiftCharArr[43] = { '`','1','2','3','4','5','6','7','8','9','0','-',
						'Q','W','E','R','T','Y','U','I','O','P','[',']',
						'A','S','D','F','G','H','J','K','L',';',
						'Z','X','C','V','B','N','M',',','.' };

	unordered_map<char, char> map;
	for (int i = 0; i < 43; i++)
	{
		map[inCharArr[i]] = shiftCharArr[i];
	}


	// ifstream inFile;
	// inFile.open("input.txt");

	// ofstream dout;
	// dout.open("output.txt");
	int inc;
	while((inc = getchar()) && inc != EOF)
	{
		if(inc == '\n')
			cout << endl;
		else if(inc == ' ')
		{
			cout << " ";
		}
		else
			cout << map[inc];
	}

	// int count = 0;
	// while (getline(cin, line))
	// {
	// 	if (count != 0)
	// 	{
	// 		cout << endl;
	// 		//dout << endl;
	// 	}
	// 	count++;

	// 	int n = line.length();


	// 	for (int i = 0; i < n; i++)
	// 	{
	// 		if (isspace(line[i]))
	// 		{
	// 			cout << " ";
	// 			//dout << " ";
	// 		}
	// 		else
	// 		{
	// 			if (map.count(line[i]) != 0)
	// 			{
	// 				cout << map[line[i]];
	// 				//dout << map[line[i]];
	// 			}
	// 			else
	// 			{
	// 				cout << line[i];
	// 				//dout << line[i];
	// 			}
				
	// 		}

	// 	}
	// }
	// inFile.close();
	// dout.close();

	return 0;
}