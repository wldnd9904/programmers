#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input1.txt", "r", stdin);
    long long int N;
    cin >> N;
    long long int res1 = N * (N - 1) * (N - 2) * (N - 3) * (N - 4);
    int res2 = 5 * 4 * 3 * 2 * 1;
    cout << res1 / res2 << "\n";
}