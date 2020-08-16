//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define Arena cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);

    



int main(){
   Arena

    int n; cin>>n;

    vector<char> a(n);

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    vector<int> s(n);
    for(int i = 0; i < n; i++){
        s[i] = 1;
        s[i] %= 10;
    }
    

    vector<pair<int,int>> blocks;

    int x[1000];
    memset(x, -1, sizeof x);

    for(int i = 1; i <= 500; i++){
        x[i] += x[i - 1];
    }

    int i, j;
    for(i = 0; i < n; i++){
        j = i;
        if(a[i] == '-'){
            while(j < n && a[j] == '-'){
                j++;
            }
            blocks.push_back({i, j - 1});
        }
        i = j;
    }

    for(i = 1; i <= 500; i++){
        x[i] += x[i - 1];
    }
    
    int ca = 0, cb = 0;
    for(i = 0; i < n; i++){
        if(a[i] == 'A')ca++;
        else if(a[i] == 'B')cb++;
    }

    for( i = 1; i <= 500; i++){
        x[i] += x[i - 1];
    }

    for(auto itt : blocks){
        if(itt.first == 0){
            j = itt.second + 1;
            if(j < n && a[j] == 'A'){
                ca += itt.second - itt.first + 1;
            }
        }else if(itt.second == n - 1){
            j = itt.first - 1;
            if(j >= 0 && a[j] == 'B'){
                cb += itt.second - itt.first + 1;
            }
        }else{
            int sz = itt.second - itt.first + 1;
            i = itt.first - 1, j = itt.second + 1;
            if(a[j] == 'A' && a[i] != 'B'){
                ca += sz;
            }else if(a[i] == 'B' && a[j] != 'A'){
                cb += sz;
            }else if(a[i] == 'B' && a[j] == 'A'){
                ca += sz/2;
                cb += sz/2;
            }
        }   
    }

    for(int i = 1; i <= 500; i++){
        x[i] += x[i - 1];
    }

    if(ca > cb){
        cout<<"A\n";
    }else if(ca < cb){
        cout<<"B\n";
    }else{
        cout<< "Coalition government\n";
    }



    




}

