#include <iostream>
#include <queue>

using namespace std;

int check(char barr[], char garr[], int n)
{
    queue<char> bq;
    queue<char> gq;
    for (int i = 0; i < n; i++)
    {
        bq.push(barr[i]);
        gq.push(garr[i]);
    }
    
    while (bq.size() != 0)
    {
        bool match = false;
        int size = gq.size();
        while (size-- > 0)
        {
            if (bq.front() == gq.front())
            {
                bq.pop();
                gq.pop();
                match = true;
                break;
            }
            else
            {
                char x = gq.front();
                gq.pop();
                gq.push(x);
            }
        }
        if (match != true)
        {
            break;
        }
    }
    return bq.size();
}

void solve()
{
    int n;
    string b, g;
    cin >> n;
    cin >> b;
    char barr[n];
    for (int i = 0; i < n; i++)
    {
        barr[i] = b.at(i);
    }
    cin >> g;
    char garr[n];
    for (int i = 0; i < n; i++)
    {
        garr[i] = g.at(i);
    }
    cout << check(barr, garr, n) << endl;
}

int main()
{
    solve();
    return 0;
}
