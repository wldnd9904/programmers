#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mysort(pair<int, int> a, pair<int, int> b)
{
    float aa = a.first, ab = a.second, ba = b.first, bb = b.second;
    return (ab / aa) > (bb / ba);
}

int main(void)
{
    vector<pair<int, int>> v;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, ret = 0, cnt = 0;
    cin >> N >> M; // N:fruits, M:coupons
    if (M == 0)
    {
        cout << N;
        return 0;
    }
    for (int i = 0; i < M; i++)
    {
        int fruits, bonus;
        cin >> fruits >> bonus;
        v.push_back({fruits, bonus});
    }
    sort(v.begin(), v.end(), mysort);
    for (int i = 0; i < M; i++)
    {
        if (cnt + v[i].first + v[i].second >= N)
        {
            if (cnt + v[i].first >= N)
            {
                ret += N - cnt;
            }
            else
            {
                ret += v[i].first;
            }
            cnt = N;
            break;
        }
        cnt += v[i].first + v[i].second;
        ret += v[i].first;
    }
    if (cnt < N)
        ret += (N - cnt);
    cout << ret;
    return 0;
}