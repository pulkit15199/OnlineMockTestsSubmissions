#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

void in(int arr[], int n)
{   int ans[n];

    for (int i = 0; i < n; i++)
    {
        int size = sizeof(arr)/sizeof(arr[0]);
        for (int j = 0; j < size; j++)
        {
            int max = 0;
            int min = 10;
            int a = arr[i] % 10;
            if (max<a){
                max = a;
            }
            if(min>a){
                min =a;
            }
            int a = (max*11) + (min*7);
            ans[i] = a;
        }
    }
    cout<<check(ans)<<endl;
}

int check(int arr[]){
    
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    in(arr, n);
}

int main()
{
    solve();
    return 0;
}
