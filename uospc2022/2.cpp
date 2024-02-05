#include <iostream>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0, M = 0, K = 0;
    cin >> N >> M >> K;
    if (N * K <= M)
    {
        cout << "YES" << endl;
        return 0;
    }
    else
        cout << "NO" << endl;
    return 0;
}