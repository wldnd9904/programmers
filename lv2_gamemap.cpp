#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int> > dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int> > map;
int visited1[100][100];
int visited2[100][100];
class State {
   public:
    int x;
    int y;
    int len;
    State(int _x, int _y, int _len) {
        x = _x;
        y = _y;
        len = _len;
    }
};
int sizeX, sizeY;
queue<State> q1, q2;

int print(vector<vector<int> > v) {
    for (vector<vector<int> >::iterator it = v.begin(); it != v.end(); it++) {
        for (vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end();
             it2++) {
            cout << *it2 << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

int produce() {
    while (!q1.empty()) {
        State state = q1.front();
        q1.pop();
        if (state.x == sizeX - 1 && state.y == sizeY - 1) {
            return state.len;
        }
        for (int i = 0; i < 4; i++) {
            const int newX = state.x + dir[i][0];
            const int newY = state.y + dir[i][1];
            if (newX >= 0 && newX < sizeX && newY >= 0 && newY < sizeY &&
                map[newX][newY] == 1 && visited1[newX][newY] == -1) {
                State tmpState = {newX, newY, state.len + 1};
                visited1[newX][newY] = tmpState.len;
                q1.push(tmpState);
            }
        }
    }
    return -1;
}
int solution(vector<vector<int> > maps) {
    memset(visited1, -1, sizeof(visited1));
    map = vector<vector<int> >(maps);
    visited1[0][0] = 1;
    sizeX = map.size();
    sizeY = map[0].size();
    State start = {0, 0, 1};
    q1.push(start);
    return produce();
}

int main(void) {
    vector<vector<int> > map = {{1, 0, 1, 1, 1},
                                {1, 0, 1, 0, 1},
                                {1, 0, 1, 1, 1},
                                {1, 1, 1, 0, 1},
                                {0, 0, 0, 0, 1}};
    cout << solution(map) << endl << endl;
}