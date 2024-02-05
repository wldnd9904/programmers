#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

long long solution(int n, vector<int> times) {
    long long l = 0, r = numeric_limits<long long>::max();
    while (l != r) {
        const long long mid = r - (r - l) / 2;
        long long sum = 0;
        for (int i = 0; i < times.size(); i++) {
            sum += mid / times[i];
            if (sum > n) break;
        }
        if (sum >= n)
            r = mid - 1;
        else
            l = mid;
    }
    long long answer = r;
    return answer;
}
int main(void) { cout << solution(6, {7, 10}) << endl; }