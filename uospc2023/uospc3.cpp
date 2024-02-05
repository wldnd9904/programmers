#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

long long dp[91];

long long fibo(int n) {
    if (dp[n] != -1) return dp[n];
    if (n == 1 || n == 2) return 1;
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(long long[91]));
    freopen("input3.txt", "r", stdin);
    int T;
    cin >> T;
    dp[1] = 1;
    dp[2] = 1;
    fibo(90);
    for (int tc = 0; tc < T; tc++) {
        bool found = false;
        int k;
        long long x;
        cin >> k >> x;
        switch (k) {
            case 1:
                for (int i = 1; i < 90; i++) {
                    if (found) break;
                    if (dp[i] == x) {
                        found = true;
                        break;
                    }
                }
                break;
            case 2:
                for (int i = 1; i < 90; i++) {
                    if (found) break;
                    for (int j = i; j < 90; j++) {
                        if (dp[i] + dp[j] == x) {
                            found = true;
                            break;
                        }
                    }
                }
                break;
            case 3:
                for (int i = 1; i < 90; i++) {
                    if (found) break;
                    for (int j = i; j < 90; j++) {
                        if (found) break;
                        for (int k = j; k < 90; k++) {
                            if (dp[i] + dp[j] + dp[k] == x) {
                                found = true;
                                break;
                            }
                        }
                    }
                }
                break;
        }
        cout << (found ? "YES" : "NO");
        if (tc != T - 1) cout << "\n";
    }
}