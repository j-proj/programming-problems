#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line1;
    string line2;
    int count = 0;

    while(getline(cin,line1) && getline(cin,line2))
    {
        // if (count > 0)
        //     cout << endl;
        // count++;

        int length_1 = line1.length();
        int length_2 = line2.length();

        int checkArr1[200] = {0};
        for (int i = 0;i < length_1; i++)
        {
            int temp1 = int(line1[i]);
            checkArr1[temp1]++;
        }

        int checkArr2[200] = {0};
        for(int i = 0;i < length_2; i++)
        {
            int temp2 = int(line2[i]);
            checkArr2[temp2]++;
        }

        for(int i = 0;i < 200; i++)
        {
            if(checkArr1[i] > 0 && checkArr2[i] > 0)
            {
                int temp1 = checkArr1[i];
                int temp2 = checkArr2[i];
                char c = i;
                if(temp1 < checkArr2[i])
                {
                    for(int j = 0;j < temp1; j++)
                    {
                        cout << c;
                    }
                }
                else
                {
                    for(int j = 0;j < temp2; j++)
                    {
                        cout << c;
                    }
                }
                
            }
        }
        cout << endl;
        
        // char temp = 112;
        // cout << temp;
        // return 0;
        
    }
}