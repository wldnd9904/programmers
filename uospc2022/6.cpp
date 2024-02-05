#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int pow[100001];
    vector<int> item;
    int weight[100001];
    vector<int> col;
    int colp[100001];
    memset(pow, 0, sizeof(pow));
    int A, B, L = 1;
    cin >> A >> B >> L;
    for (int i = 1; i <= A; i++)
    {
        int a, b;
        cin >> a >> b;
        item.push_back(a);
        pow[a] -= b;
    }
    for (int i = 1; i <= B; i++)
    {
        int a, b;
        cin >> a >> b;
        pow[a] += b;
        for (int j = 1; j < b; j++)
        {
            if (a - j >= 1)
                pow[a - j] += b - j;
            if (a + j <= L)
                pow[a + j] += b - j;
            if (a - j < 1 && a + j > L)
                break;
        }
    }
    for (vector<int>::iterator i = item.begin(); i < item.end(); i++)
    {
        if (pow[*i] < 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}