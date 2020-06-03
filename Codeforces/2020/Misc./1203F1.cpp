#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
 
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
 
const ll INF = 1e18;
const ll MOD = 998244353;
const ll MX = 1000001;
 
ll N, R, A, B;
 
void solve() {
    cin >> N >> R;
    vector<l_l> adds, subs;
    
    for (int i = 0; i < N; i++) {
		cin >> A >> B;
		if (B >= 0) adds.push_back({A, B});
		else subs.push_back({A + B, A});
	}
    sort(adds.begin(), adds.end());
    sort(subs.begin(), subs.end(), greater<l_l>());
    
    bool pos = true;
    for (auto& i : adds) {
		if (i.first > R) {
			pos = false;
			break;
		} else {
			R += i.second;
		}
	}
	
	for (auto& i : subs) {
		if (i.second > R) {
			pos = false;
			break;
		} else {
			R += i.first;
		}
	}
    
    // cout << pos << " " << R << "\n";
    if (pos && R >= 0) cout << "YES";
    else cout << "NO";
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T = 1; // cin >> T;
    while (T--) solve();
    return 0;
    // You should actually read the stuff at the bottom
}
 
/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
