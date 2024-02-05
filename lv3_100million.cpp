#include <iostream>
#include <string>
#include <vector>

using namespace std;

// n, m : x,y 사이즈, r,c: 목적지, k: 경로길이
// d l r u
// r-x, c-y 만큼 u/d, l/r, 격자탈출안됨, 최소조건 정해놓고 짝 임의로 더하기, d가
// 첨에 많이 나올수록 좋음,
string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    const int dx = r - x;
    const int dy = c - y;
    k -= (abs(dy) + abs(dx));
    // 불가능: spare가 음수거나 홀수일 때
    if (k < 0 || k % 2 == 1) return "impossible";
    // spare가 0일 때 - 최단경로
    else if (k == 0) {
        for (int i = 0; i < dx; i++) {
            answer.push_back('d');
        }
        for (int i = 0; i > dy; i--) {
            answer.push_back('l');
        }
        for (int i = 0; i < dy; i++) {
            answer.push_back('r');
        }
        for (int i = 0; i > dx; i--) {
            answer.push_back('u');
        }
        return answer;
    }
    // spare 있을 때:
    int D = 0, L = 0, R = 0, U = 0;
    if (x > r)
        U += x - r;
    else
        D += r - x;
    if (y > c)
        L += y - c;
    else
        R += c - y;

    answer += string(D, 'd');
    int d = min(k / 2, n - (x + D));
    answer += string(d, 'd');
    U += d;
    k -= 2 * d;

    answer += string(L, 'l');
    int l = min(k / 2, y - L - 1);
    answer += string(l, 'l');
    R += l;
    k -= 2 * l;

    for (int i = 0; i < k / 2; i++) answer += "rl";
    answer += string(R, 'r');
    answer += string(U, 'u');
    return answer;
}

int main(void) { cout << solution(3, 4, 2, 3, 3, 1, 5) << endl; }