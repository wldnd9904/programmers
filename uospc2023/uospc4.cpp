#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input4.txt", "r", stdin);
    long long k;
    cin >> k;
    if (k < 10) {
        cout << k << endl;
        return 0;
    }
    long long jari = 1;
    long long mult = 9;
    long long tmpk = k;
    while (k > 0) {
        tmpk -= jari * mult;
        if (tmpk <= 0) break;
        k -= jari * mult;
        jari++;
        if (jari & 1) mult *= 10;
    }
    char ret;
    long long cnt = ceil((double(k) / jari));
    k %= jari;
    if (k == 0) {
        k = jari;
    }
    if (jari & 1) {
        cnt--;
        cnt += pow(10, jari / 2);
        string s = to_string(cnt);
        string rs = to_string(cnt / 10);
        reverse(rs.begin(), rs.end());
        ret = (s + rs)[k - 1];
    } else {
        if (jari > 2) {
            cnt--;
            cnt += pow(10, jari / 2 - 1);
        }
        string s = to_string(cnt);
        string rs = to_string(cnt);
        reverse(rs.begin(), rs.end());
        ret = (s + rs)[k - 1];
    }
    cout << ret << "\n";
}