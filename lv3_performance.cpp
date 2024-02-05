#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 0;
    vector<vector<int>>::iterator it = scores.begin();
    vector<int> wanho = (*it);
    int rank[200000];
    memset(rank, 0, sizeof(rank));
    int wanhos = wanho[0] + wanho[1];
    rank[wanho[0] + wanho[1]] = 1;
    int Bs[100000];  // Bs[A] = B
    memset(Bs, -1, sizeof(Bs));
    int As[100000];  // As[B] = A
    memset(As, -1, sizeof(As));
    Bs[wanho[0]] = wanho[1];
    As[wanho[1]] = wanho[0];
    for (++it; it != scores.end(); it++) {
        vector<int> candi = (*it);
        if (candi[0] + candi[1] >= wanhos) {
            Bs[candi[0]] = max(Bs[candi[0]], candi[1]);
            As[candi[1]] = max(As[candi[1]], candi[0]);
        }
    }
    it = scores.begin();
    for(int i = (*it)[0]; )
    for (++it; it != scores.end(); it++) {
        vector<int> candi = (*it);
        if (candi[0] + candi[1] >= wanhos) {
            Bs[candi[0]] = max(Bs[candi[0]], candi[1]);
            As[candi[1]] = max(As[candi[1]], candi[0]);
        }
    }
    return answer;
}

int main(void) {
    vector<vector<int>> scores = {{2, 2}, {1, 4}, {3, 2}, {3, 2}, {2, 1}};
    cout << solution(scores) << endl;
    return 0;
}