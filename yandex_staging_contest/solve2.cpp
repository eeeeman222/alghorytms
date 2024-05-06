#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<set>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    int q; cin >> q;
    vector<string>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int mid = 0;
    while(q--) {
        int len;
        cin >> len;
        string pref;
        cin >> pref;
        int l = 0;
        int r = n - 1;
        while (r - l > 0) {
            mid = (r + l) / 2;
            if (pref > a[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int isans = 0;
        if(a[r].find(pref) != 0){
            cout << -1 << endl;
            isans = 1;
        }
        else if (r + len <= n) {
            if (a[r + len - 1].find(pref) == 0) {
                cout << r + len << endl;
                isans = 1;
            }
        }
        if(isans == 0){
            cout << -1 << endl;
        }
    }
}

signed main(){
    int t = 1; //cin >> t;
    while(t--){
        solve();;
    }
}