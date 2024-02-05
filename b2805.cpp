#include <iostream>
#include <vector>
using namespace std;
long long tree[1000001];
int N, M;
bool canGet(int m) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (tree[i] > m) sum += (tree[i] - m);
    }
    return sum >= M;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }
    int l = 0, r = 2147483647;
    while (l != r) {
        int mid = l + (r - l) / 2;
        if (canGet(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << max(l - 1, 0) << endl;
    return 0;
}