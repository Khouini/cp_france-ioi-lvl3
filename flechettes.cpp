#include <iostream>
using namespace std;
int main()
{
    // cout << "Entrez le nombre de lettres: ";
    int n = 5;
    // cin >> n;

    if (n < 1 || n > 26)
    {
        return 0;
    }

    bool weBack = false;
    int loopSize = n * 2 - 1;
    int startInterval = 0, endInterval = loopSize - 1;
    char myArray[9] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
    int updateValue = 1;
    for (int i = 0; i < loopSize; i++)
    {
        for (int j = 0; j < loopSize; j++)
        {
            bool isFirstLine = (i == 0);
            bool beforeLastColumn = j < loopSize - 1;
            bool allowedUpdate = j > startInterval && j < endInterval;
            bool lastColum = j == loopSize - 1;
            bool mediumAttempt = (i == (loopSize) / 2);
            if (!isFirstLine && beforeLastColumn && allowedUpdate)
            {
                myArray[j] = myArray[j] + updateValue;
            }
            cout << myArray[j];
            if (lastColum)
            {
                if (!isFirstLine)
                {
                    if (mediumAttempt)
                    {
                        // startInterval = j;
                        // endInterval = j;
                        weBack = true;
                        updateValue = -1;
                    }
                    else
                    {
                        if (weBack)
                        {
                            startInterval--;
                            endInterval++;
                        }
                        else
                        {
                            startInterval++;
                            endInterval--;
                        }
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}