#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

int cadbury(int l, int w)
{
    if (l < 1 || w < 1)
    {
        return 0;
    }
    if (l == 1 && w == 1)
    {
        return 1;
    }
    int next = min(l, w);
    int ans = cadbury(max(l, w) - next, next);
    return ans+1;
}

void solve()
{
    int minl;
    cin >> minl;
    int maxl;
    cin >> maxl;
    int minw;
    cin >> minw;
    int maxw;
    cin >> maxw;
    int c = 0;
    for (int i = 0; i <= maxl - minl; i++)
    {
        for (int j = 0; j <= maxw - minw; j++)
        {
            c += cadbury(minl + i, minw + j);
        }
    }
    cout << c << endl;
    // cout<<cadbury(13,29);
}

int main()
{
    solve();
    return 0;
}
