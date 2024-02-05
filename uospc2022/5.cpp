#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dfs();
char map[2001][2001];
int N = 0, M = 0, ret = 0;
int main(void)
{
    memset(map, -1, sizeof(char[2001][2001]));
    cin >> N >> M;
    cout << N << M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            map[i][j] = getchar();
        }
        cout << "next\n";
        getchar(); //줄바꿈 무시
    }
    cout << "gd";
    cout << dfs() << endl;
    return 0;
}

int dfs()
{
    char newmap[2002][2002];
    int X = 1, Y = 1, time = 0, mode = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            newmap[i][j] = map[i][j];
        }
    }
    pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<pair<int, int>> stack;
    stack.push_back({1, 1});
    while (true)
    {
        while (mode == 0)
        {
            for (int dr = 0; dr < 4; dr++)
            {
                cout << X << "," << Y << "," << dr << endl;
                if (X == N && Y == M)
                {
                    return time;
                }
                if (newmap[X + dir[dr].first][Y + dir[dr].second] == '#' || X + dir[dr].first < 1 || X + dir[dr].first > N || Y + dir[dr].second < 1 || Y + dir[dr].second > M)
                {
                    if (dr == 3)
                    {
                        time++;
                        newmap[X][Y] = '#';
                        cout << "no";
                        mode = 1;
                        break;
                    }
                    continue;
                }
                newmap[X][Y] = '#';
                time++;
                stack.push_back({X, Y});
                X = X + dir[dr].first;
                Y = Y + dir[dr].second;
            }
        } //갈곳이없음
        while (stack.size() > 0)
        {
            cout << "popmode" << endl;
            pair<int, int> pos = stack[stack.size() - 1];
            stack.pop_back();
            time++;
            X = pos.first;
            Y = pos.second;
            if (newmap[X - 1][Y] == '.' || newmap[X + 1][Y] == '.' || newmap[X][Y - 1] == '.' || newmap[X][Y + 1] == '.')
            {
                mode = 0;
                break;
            }
        }
        mode = 0;
    }
}