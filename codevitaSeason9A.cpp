//Created by Kira

#include<bits/stdc++.h>
using namespace std;


#define all(x) x.begin(), x.end()


const int mod = 1e9 + 7;

long long pwr(long long a, long long b);
    
const int N = 105;



void rotateMatrix(vector<vector<char>>& mat, int n) 
{
    for(int x = 0; x < n/2; x++){
        for(int y = x; y < n - x - 1; y++){
            char temp = mat[x][y];
            mat[x][y] = mat[y][n - 1 - x]; 
            mat[y][n - 1 - x] = mat[n - 1 - x][n - 1 - y]; 
            mat[n - 1 - x][n - 1 - y] = mat[n - 1 - y][x]; 
            mat[n - 1 - y][x] = temp; 
        }
    } 
} 

vector<vector<int>> create(vector<vector<char>> &a, int n){
    
    vector<vector<int>> res(n, vector<int>(n, 0));

    int cnt = 0;

    for(int j = 0; j < n; j++){
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i][j] == 'C')
                cnt++;
        }

        for(int i = n - 1; i >= 0; --i){
            if(cnt > 0){
                res[i][j] = 1;
                cnt--;
            }
        }
    }

    return res;
}

int fun(vector<vector<int>> &b, int n){

    int i, j;
    int dp[n][n];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[i][j] ^= 1;
        }
    }

    for(int i = 0; i < n; i++){
        dp[i][0] = b[i][0];
    }
    for(int i = 0; i < n; i++){
        dp[0][i] = b[0][i];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(b[i][j]){
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }else{
                dp[i][j] = 0;
            }
        }
    }
    
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mx = max(mx, dp[i][j]);
        }
    }

    return mx;

}

// int help(vector<vector<int>> &b, int n){
    
//     vector<int> left(n), right(n), up(n);
//     left[0] = b[n - 1][0];
//     for(int j = 1; j < n; j++){
//         if(b[n - 1][j]){
//             left[j] = left[j - 1] + 1;
//         }else{
//             left[j] = 0;
//         }
//     }
//     right[n - 1] = b[n - 1][n - 1];
//     for(int j = n - 2; j >= 0; --j){
//         if(b[n - 1][j]){
//             right[j] = right[j + 1] + 1;
//         }else{
//             right[j] = 0;
//         }
//     }

//     for(int j = 0; j < n; j++){
//         int i = n - 1;
//         while(i >= 0 && b[i][j] == 1){
//             up[j]++;
//             i--;
//         }
//     }
//     int mx = 0;
//     for(int i = 0; i < n; i++){
//         mx = max(mx, min(up[i], max(left[i], right[i])));
//     }

//     return mx;
// }

void display(vector<vector<int>> &b, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<b[i][j]<<" ";
        }cout<<'\n';
    }
}

int main(){
   cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);

    int n; cin>>n;

    vector<vector<char>> a(n, vector<char> (n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }

    int vasu[1000];
    for(int i = 1; i <= 100; i++){
        vasu[i]++;
        vasu[i] %= 10;
    }


    int mx = 0, v;
    vector<vector<int>> b;
    b = create(a, n);
    v = fun(b, n);
    // cout<<v<<" ";
    //display(b, n);
    mx = max(mx, v);

    rotateMatrix(a, n);
    b = create(a, n);
    v = fun(b, n);
    //cout<<v<<" ";
    mx = max(mx, v);
    rotateMatrix(a, n);
    b = create(a, n);
    v = fun(b, n);
   // cout<<v<<" ";
    mx = max(mx, v);

    rotateMatrix(a, n);
    b = create(a, n);
    v = fun(b, n);
    mx = max(mx, v);
    //cout<<v<<"\n";
    rotateMatrix(a, n);
    b = create(a, n);
    v = fun(b, n);
    mx = max(mx, v);

     for(int i = 1; i <= 100; i++){
        vasu[i]++;
        vasu[i] %= 10;
    }

    cout<<mx<<'\n';

}

long long pwr(long long a, long long b){
   a %= mod;	//Remove mod if not required
   long long res = 1;
   while(b > 0){
    if(b&1) res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}