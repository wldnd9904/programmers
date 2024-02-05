#include <iostream>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q = 0, K = 0, sum = 0, before = -1, wasPurple = -1;
    int min, max;
    cin >> Q >> K;
    getchar(); //줄바꿈 무시
    int r = 0, ip = 0;
    cin >> r >> ip;
    wasPurple = ip;
    before = sum;
    sum += r;
    if (ip)
    {
        min = K - sum;
    }
    else
    {
        max = K - sum - 1;
    }
    for (int i = 0; i < Q-1; i++)
    {
        int rating = 0, isPurple = 0;
        cin >> rating >> isPurple;
        if (isPurple && !wasPurple) // now purple
        {
            if (max < K - sum - 1)
                max = K - sum - 1;
            if (min > K - sum - rating)
                min = K - sum - rating;
        }
        if (!isPurple && wasPurple) // now not purple
        {
            if (max < K - 1 - sum + rating)
                max = K - 1 - sum + rating;
            if (min > K - sum)
                min = K - sum;
        }
        sum += rating;
        wasPurple = isPurple;
    }
    cout << min << " " << max << endl;

    return 0;
}