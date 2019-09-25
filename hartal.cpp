#include <iostream>
#include <string>

using namespace std;

int main()
{
    int caseNum;
    cin >> caseNum;
    //cout << caseNum << endl;
    for (int i = 0;i < caseNum; i++)
    {
        int days;
        cin >> days;
        int parties;
        cin >> parties;
        int hartalCount = 0;

        int hartTrack[days + 1];
        for (int j = 0;j <= days; j++)
        {
            hartTrack[j] = -1;
        }
        //cout << "days: " << days << " parties: " << parties << endl;
        for (int j = 0;j < parties; j++)
        {
            int hartals;
            cin >> hartals;
            //cout << "hartals: " << hartals << endl;
            //cout << "days: " << days << endl;
            for (int k = 1;k <= days; k++)
            {
                //cout << "d";
                
                if (k % hartals == 0)
                { 
                    //need to check if the hartal has already been
                    //counted on a previus day, do not need to count
                    //hartals twice
                    //cout << "x day " << k;
                    if ((k % 7 != 6) && (k % 7 != 0))
                    {
                        if (hartTrack[k] == -1)
                        {
                            hartTrack[k] = 1;
                            //cout << "hartal add day#: " << k;
                            hartalCount++;
                        }
                    }
                }
                else
                {
                    //cout << " ";
                }
                
            }
            //cout << endl;
            //cout << "party " << j+1 << " hartals: " << hartalCount << endl;
        }
        cout << hartalCount << endl;
    }

    return 0;
}