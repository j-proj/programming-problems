#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{   
    string s;
    while (getline(cin, s))
    {
        istringstream is(s);
        
        int count = 1;
        int n = 0;
        int max = 1;
        is >> max;
        int num[max + 1];// = {0};
        num[0] = max;
        if (max ==1)
        {
            cout << "Jolly" << endl;
        }
        else
        {
            while (is >> n)
            {
                num[count] = n;
                count++;
            }
            
            // for(int i = 0;i < count; i++)
            // {
            //     cout << num[i] << " ";
            // }
            // cout << endl;
            //cout << "max: " << max << " count: " << count << endl;
            int diffArr[3000] = {-1};
            for(int i = 1;i < count - 1; i++)
            {
                diffArr[i] = abs(num[i+1] - num[i]);
                //cout << "diff: " << diffArr[i];
            }
            //cout << endl;

            int jollyArr[max];
            for(int i = 1;i < count; i++)
            {
                jollyArr[i] = -1;
            }
            for(int i = 1;i < count; i++)
            {
                //cout << diffArr[i] << " ";
                int temp = diffArr[i];
                jollyArr[temp] = temp;
            }
            //cout << endl;
            //bool jolly = false;
            bool notJolly = false;
            for(int i = 1;i < count - 1; i++)
            {
                //cout << jollyArr[i] << " ";
                if(jollyArr[i] < 1)
                {
                    notJolly = true;
                }
            }
            if(notJolly)
            {
                cout << "Not jolly" << endl;
            }
            else
            {
                cout << "Jolly" << endl;
            }
        }

        //cout << endl;

    }

    return 0;
}