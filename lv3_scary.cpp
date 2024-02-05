#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int N, M;

struct node {
    int y, x, d, heuristic;
};
struct cmp {
    bool operator()(node a, node b) { return a.heuristic > b.heuristic; }
};

int main(int argc, char** argv) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    freopen("lv3_scary.txt", "r", stdin);
    cin >> N >> M;
    vector<vector<bool>> wall(N, vector<bool>(M, false));
    vector<pair<int, int>> ghost;
    pair<int, int> start, goal;
    for (int y = 0; y < N; y++) {  // input
        string line;
        cin >> line;
        for (int x = 0; x < M; x++) {
            switch (line[x]) {
                case 'D':
                    goal = {y, x};
                    break;
                case '.':
                    break;
                case 'G':
                    ghost.push_back({y, x});
                    break;
                case 'N':
                    start = {y, x};
                    break;
                case '#':
                    wall[y][x] = true;
                    break;
            }
        }
    }  // endof input

    bool answer = false;
    priority_queue<node, vector<node>, cmp> q;

    int curd = 0;
    node init = {start.first, start.second, 0};
    q.push(init);
    while (!q.empty()) {
        node cur = q.top();
        wall[cur.y][cur.x] = true;
        // cout << cur.heuristic;
        q.pop();
        bool brk = false;
        for (auto it = ghost.begin(); it != ghost.end(); it++) {
            if (abs(cur.y - (*it).first) + abs(cur.x - (*it).second) <= cur.d) {
                brk = true;
                break;
            }
        }
        if (brk) continue;
        if (cur.x == goal.second && cur.y == goal.first) {
            answer = true;
            break;
        }
        for (int dir = 0; dir < 4; dir++) {
            node cand = {cur.y + dy[dir], cur.x + dx[dir], cur.d + 1,
                         abs(cur.y + dy[dir] - goal.first) +
                             abs(cur.x + dx[dir] - goal.second)};
            if (cand.x >= 0 && cand.x < M && cand.y >= 0 && cand.y < N &&
                !wall[cand.y][cand.x])
                q.push(cand);
        }
    }
    cout << (answer ? "Yes" : "No") << "\n";

    return 0;
}