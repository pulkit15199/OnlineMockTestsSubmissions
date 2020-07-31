#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

bool check(int arr1[], int arr2){

}

int order(int arr[], int n)
{

    for (int i = 1; i <= n; i++)
    {
        arr[arr[i]] = arr[i];

    }
    cout << check(ans) << endl;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {int size;
    cin >> size;
        int arr[size];
        for (int j = 0; j < size; j++)
        {
            cin >> arr[j];
        }
        order(arr, size);
    }
}

int main()
{
    solve();
    return 0;
}
