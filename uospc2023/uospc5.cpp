#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second >= b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input5.txt", "r", stdin);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        q.push({s, e});
    }
    vector<int> v(K, 0);
    int ret = 0;
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 0; i < K; i++) {
            if (v[i] < p.first) {
                v[i] = p.second;
                ret++;
                break;
            }
        }
    }
    cout << ret << "\n";
}