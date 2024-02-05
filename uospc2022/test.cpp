#include <iostream>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int seat[100][100];
    int N, M, ret = 0;
    cin >> N >> M;
    getchar(); //줄바꿈 무시
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            seat[i][j] = getchar();
        }
        getchar(); //줄바꿈 무시
    }
    cout << "hi";
    return 0;
}