#include <iostream>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0, sum = 0, max = -1;
    cin >> N;
    getchar(); //줄바꿈 무시
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
        if (tmp > max)
            max = tmp;
    }
    int div = sum / max;
    if (max * div == sum)
    {
        cout << max * div << endl;
        return 0;
    }
    if (max * div < sum)
    {
        cout << max * (div + 1) << endl;
        return 0;
    }
}