#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<set>
using namespace std;
#define int long long

void solve() {
    string s;
    getline(cin, s);
    int len = 0;
    int k = 0;
    for(int i = 0; i < s.size(); i++){
        if((s[i] == ' ')||(s[i] == ',')){
            len = max(len, k);
            k = 0;
        }
        else{
            k+=1;
        }
    }
    len = max(len, k);

    len = len * 3;
    int string_cnt = 0;
    string word = "";
    bool fw = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ','){
            word += s[i];
        }
        if((s[i] == ' ')||(s[i] == ',')){
            if(i < s.size() - 1){
                if(s[i + 1] == ','){
                    continue;
                }
            }
            if((word.size() + 1 > len - string_cnt) && (word.size() != 0)){
                cout << endl << word;
                string_cnt = word.size();
                word = "";
            }
            else {
                if (word != "") {
                    if(fw == 1){
                        string_cnt += word.size();
                    }
                    else{
                        cout << " ";
                        string_cnt += word.size() + 1;
                    }
                    cout << word;
                    fw = 0;
                    word = "";
                }
            }
        }
        else{
            word += s[i];
        }
    }
    if(word != ""){
        if(word.size() > len - string_cnt - 1){
            cout << endl << word;
        }
        else{
            cout << ' ' << word;
        }
    }
}


signed main(){
    int t = 1; //cin >> t;
    while(t--){
        solve();;
    }
}