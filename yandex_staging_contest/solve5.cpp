#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<set>
using namespace std;
#define int long long

struct Node {
    vector<pair<char, Node*>> children;
    pair<int, int> maxi = {-100, -100};
    Node* anc = nullptr;
};

void add(string& s, Node* a, pair<int, int> popularity, int idx = 0) {
    if (idx == s.size()) {
        a->maxi = max(a->maxi, popularity);
        return;
    }

    bool found = false;
    for (int i = 0; i < a->children.size(); i++) {
        if (a->children[i].first == s[idx]) {
            add(s, a->children[i].second, popularity, idx + 1);
            found = true;
        }
    }

    if (!found) {
        Node* bc = new Node;
        bc->anc = a;
        a->children.emplace_back(s[idx], bc);
        add(s, bc, popularity, idx + 1);
    }
}

pair<int, int> pulling(Node* a) {
    for (int i = 0; i < a->children.size(); i++) {
        pair<int, int> res = pulling(a->children[i].second);
        a->maxi = max(a->maxi, res);
    }
    return a->maxi;
}

void solve() {
    int n, q;
    cin >> n >> q;
    int trash = 0;
    Node* beg = new Node;

    for (int i = 0; i < n; i++) {
        string s; int popularity;
        cin >> s >> popularity;
        add(s, beg, {popularity, i + 1});
    }
    pulling(beg);

    while(q--) {
        char a; cin >> a;
        if (a == '-') {
            if (trash == 0) {
                beg = beg->anc;
                cout << beg->maxi.second << '\n';
            } else {
                trash--;
                if (trash == 0) {
                    cout << beg->maxi.second << '\n';
                } else {
                    cout << "-1" << endl;
                }
            }
        } else {
            char b; cin >> b;
            if (trash != 0) {
                trash++;
                cout << "-1" << endl;
                continue;
            }

            bool rite = false;
            for (int i = 0; i < beg->children.size(); i++) {
                if (beg->children[i].first == b) {
                    rite = true;
                    beg = beg->children[i].second;
                    cout << beg->maxi.second << endl;
                    break;
                }
            }
            if (!rite) {
                trash++;
                cout << "-1" << endl;
            }
        }
    }
}

signed main(){
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}