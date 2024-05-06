#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<set>
using namespace std;
#define int long long


void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 2;
        return;
    }
    string s;
    cin >> s;
    s = 'R' + s;
    n++;
    set<int> ans;
    int pos = 1;
    vector<pair<int, int>> dp(n);
    vector<int> dir(n);
    vector<int> fc(n);
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        fc[i] = cnt;
        if(s[i] == 'F'){
            cnt++;
        }
        else{
            cnt = 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            pos = -1;
        }
        if(s[i] == 'R'){
            pos = 1;
        }
        dir[i] = pos;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != 'F'){
            sum += dir[i] * fc[i];
        }
    }
    for(int i = 1; i < n; i++){
        if(s[i] == 'F'){
            int lsum = sum - dir[i]*(fc[i] + 1) - fc[i];
            ans.insert(lsum);
            int rsum = sum - dir[i]*(fc[i] + 1) + fc[i];
            ans.insert(rsum);
        }
        if(s[i] == 'L'){
            int rsum = sum + 2 * fc[i];
            ans.insert(rsum);
            int fsum = sum + fc[i]+ dir[i - 1]*(fc[i] + 1);
            ans.insert(fsum);
        }
        if(s[i] == 'R'){
            int lsum = sum - 2 * fc[i];
            ans.insert(lsum);
            int fsum = sum - fc[i] + dir[i - 1]*(fc[i] + 1);
            ans.insert(fsum);
        }
    }
    cout << ans.size();
}

signed main(){
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}