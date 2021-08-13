#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "sbox1"
#define inf 999999999
#define maxn 100009

int n, m;
int s[maxn];

void update(int x, int v){
    while(x <= n){
        s[x] += v;
        x += x & -x;
    }
}

int get(int x){
    int res = 0;
    while(x){
        res += s[x];
        x -= x & -x;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m;
    while(m --){
        int t, l, r, d;
        cin >> t;
        if(t == 1){
            cin >> l >> r >> d;
            update(l, d);
            update(r + 1, -d);
        }
        else{
            cin >> l;
            cout << get(l) << "\n";
        }
    }
    return 0;
}