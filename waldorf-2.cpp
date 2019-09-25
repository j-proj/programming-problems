#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

bool checkdirectional(string dir,
	char arr[][51], int row, int col, string name, int count)
{
	//cout << "checking: " << dir << "space check" << endl;
	char temp = arr[row][col];

	if (count >= name.length()/* && arr[row][col] == name[count]*/)
		return true;

	if (arr[row][col] != name[count])
		return false;
	

	if (dir == "up") {
		row = row - 1;
	}
	else if (dir == "upl") {
		row = row - 1;
		col = col - 1;
	}
	else if (dir == "upr") {
		row = row - 1;
		col = col + 1;
	}
	else if (dir == "left") {
		//row = row + 1;
		col = col - 1;
	}
	else if (dir == "right") {
		col = col + 1;
	}
	else if (dir == "down") {
		row = row + 1;
	}
	else if (dir == "downr") {
		row = row + 1;
		col = col + 1;
		//cout << "going to: " << row << " " << col << endl;
		//cout << "which holds val: " << arr[row][col] << endl;
	}
	else if (dir == "downl") {
		row = row + 1;
		col = col - 1;
	}

	return checkdirectional(dir, arr, row, col, name, count + 1);
}

bool check(char arr[][51], int row, int col, string name, int count)
{
	if (arr[row][col] != name[count])
		return false;
	if (count >= name.length() && arr[row][col] == name[count])
		return true;
	//cout << "orig check" << endl;
	bool up = checkdirectional("up", arr, row - 1, col, name, count + 1);
	bool upl = checkdirectional("upl", arr, row - 1, col - 1, name, count + 1);
	bool upr = checkdirectional("upr", arr, row - 1, col + 1, name, count + 1);
	bool left = checkdirectional("left", arr, row, col - 1, name, count + 1);
	bool right = checkdirectional("right", arr, row, col + 1, name, count + 1);
	bool down = checkdirectional("down", arr, row + 1, col, name, count + 1);
	bool downl = checkdirectional("downl", arr, row + 1, col - 1, name, count + 1);
	bool downr = checkdirectional("downr", arr, row + 1, col + 1, name, count + 1);

	if (up || upl || upr || left || right || down || downl || downr)
		return true;
	else
	{
		return false;
	}


}



int main()
{
	//ifstream cin;
	//ofstream cout;
	//cin.open("input.txt");
	//cout.open("output.txt");
	int caseN;
	cin >> caseN;
	for (int c = 0; c < caseN; c++)
	{
		if (c > 0)
		{
			cout << endl;
		}
		int row = 0;
		int col = 0;
		cin >> row >> col;
		cin.ignore();

		char arr[21][51];
		for (int i = 0; i < row; i++)
		{
			string line;
			getline(cin, line);
			for (int j = 0; j < col; j++)
			{
				arr[i][j] = tolower(line[j]);
			}
		}

		 /*for(int i = 0;i<row;i++)
		 {
		     for(int j = 0;j<col;j++)
		         cout << arr[i][j];
		     cout << endl;
		 }*/

		int k = 0;
		cin >> k;
		cin.ignore();
		string nameArr[21];
		for (int i = 0; i < k; i++)
		{
			string temp;
			getline(cin, temp);
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			nameArr[i] = temp;
			//cout << nameArr[i] << endl;

		}

		for (int i = 0; i < k; i++)
		{
			int firstRow = 100;
			int firstCol = 100;
			for (int r = 0; r < row; r++)
			{
				for (int c = 0; c < col; c++)
				{
					//cout << "name: " << nameArr[i] << " row: " << r << " col: " << c << endl;
					if (nameArr[i][0] == arr[r][c])
					{
						bool in = false;
						//cout << endl << "checking letter" << nameArr[i][0] << endl;
						in = check(arr, r, c, nameArr[i], 0);
						if (in)
						{
							//cout << endl;
							//cout << "found word" << endl;
							if (r < firstRow)
							{
								firstRow = r;
								firstCol = c;
							}
							else if (r == firstRow && c < firstCol)
							{
								firstCol = c;
							}
						}
						else
						{
							//cout << "not found" << endl;
						}

					}
				}
			}
			cout << firstRow + 1 << " " << firstCol + 1 << endl;
		}

	}
	// int ch;
	// while((ch = getchar()) && (ch != EOF))
	// {

	// }
}