#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    if (triangle.size() == 1) return triangle[0][0];
    vector<vector<int>> v;
    v.push_back({triangle[0][0]});
    for (int i = 1; i < triangle.size(); i++) {
        vector<int> tmpv(i + 1);
        for (int j = 0; j < triangle[i].size(); j++) {
            int leftup = (j == 0) ? 0 : v[i - 1][j - 1];
            int rightup = (j == triangle[i].size() - 1) ? 0 : v[i - 1][j];
            tmpv[j] = triangle[i][j] + max(leftup, rightup);
        }
        v.push_back(tmpv);
    }
    int answer = 0;
    for (int i = 0; i < v[v.size() - 1].size(); i++) {
        answer = max(answer, v[v.size() - 1][i]);
    }
    return answer;
}

int main(void) {
    vector<vector<int>> triangle = {
        {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    cout << solution(triangle) << endl;
}