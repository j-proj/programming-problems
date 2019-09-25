#include <iostream>
#include <string>
#include <vector>

using namespace std;

string unrank(int rankNum)
{
    string rank;
    string suit;
    if (rankNum > 0 && rankNum < 14)
    {
        suit = "Clubs";
    }
    else if(rankNum >= 14 && rankNum <= 26)
    {
        suit = "Diamonds";
    }
    else if(rankNum >= 27 && rankNum <= 39)
    {
        suit = "Hearts";
    }
    else
    {
        suit = "Spades";
    }

    int modRes = rankNum % 13;
    if(modRes > 0 && modRes < 10)
    {
        rank = to_string(modRes + 1);
    }
    else if (modRes == 10)
    {
        rank = "Jack";
    }
    else if (modRes == 11)
    {
        rank = "Queen";
    }
    else if (modRes == 12)
    {
        rank = "King";
    }
    else
    {
        rank = "Ace";
    }

    return (rank + " of " + suit);
}

int main()
{


    int caseNum = 0;

    int knownShuffles = 0;
 
    cin >> caseNum;
    int count = 0;
    while (cin>>knownShuffles)
    {
        int shuffleArr[knownShuffles+1][53];
        for (int i = 1; i <= knownShuffles; i++)
        {
            for (int j = 1;j < 53; j++)
            {
                cin >> shuffleArr[i][j];
            }
        }

        cin.ignore();

        vector<int> shuffleOrder;
        string line;
        while(getline(cin, line) && line != "")
        {
            int temp = stoi(line);
            shuffleOrder.push_back(temp);
        }

        int origArr[53];
        for (int i = 1; i < 53; i++)
        {
            origArr[i] = i;
        }
        
        int procArray[53];
        for (auto x: shuffleOrder)
        {
            for (int i = 1;i < 53; i++)
            {
                int index = shuffleArr[x][i];
                procArray[i] = origArr[index];
            }
            copy(begin(procArray), end(procArray), begin(origArr));
        }

        for (int i = 1;i < 53; i++)
        {
            cout << unrank(origArr[i]) << endl;
        }
        count++;
        
        if(count < caseNum)
            cout << endl;
    }

    return 0;
    
}