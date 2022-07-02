#include <cmath>
using namespace std;
int able(int, int);

int solution(int n)
{
    int answer = able(n, 0);
    return answer;
}

int able(int n, int m)
{
    if (log(n) / log(3) < m / 2)
        return 0;
    if (n == 3 && m == 2)
        return 1;
    if (n % 3 == 0 && m >= 2)
        return able(n / 3, m - 2) + able(n - 1, m + 1);
    return able(n - 1, m + 1);
}