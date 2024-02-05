#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input2.txt", "r", stdin);
    int N, K;
    string s;
    cin >> N >> K;
    cin >> s;
    if (N < 2) {
        cout << s;
        return 0;
    }

    for (int i = K - 1; i < N; i++) cout << s[i];

    if ((N - K) & 1)
        for (int i = 0; i <= K - 2; i++) cout << s[i];
    else
        for (int i = K - 2; i >= 0; i--) cout << s[i];
}