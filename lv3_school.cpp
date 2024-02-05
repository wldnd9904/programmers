#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<vector<bool>> ispuddle(n, vector<bool>(m, false));
    for (auto it = puddles.begin(); it != puddles.end(); it++)
        ispuddle[(*it)[1] - 1][(*it)[0] - 1] = true;
    bool flag = false;
    for (int i = 0; i < m; i++) {
        if (ispuddle[0][i]) flag = true;
        v[0][i] = flag ? 0 : 1;
    }
    flag = false;
    for (int j = 0; j < n; j++) {
        if (ispuddle[j][0]) flag = true;
        v[j][0] = flag ? 0 : 1;
    }
    for (int y = 1; y < n; y++) {
        for (int x = 1; x < m; x++) {
            if (ispuddle[y][x])
                v[y][x] = 0;
            else
                v[y][x] = v[y - 1][x] + v[y][x - 1];
        }
    }
    return v[n - 1][m - 1];
}

int main(void) { cout << solution(4, 3, {{2, 2}}) << endl; }