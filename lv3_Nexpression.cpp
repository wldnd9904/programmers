#include <iostream>
#include <string>
#include <vector>
using namespace std;

int numbers[1000000];
vector<int> v;
int solution(int N, int number) {
    int answer = 0;
    const int base[7] = {0, 1, 11, 111, 1111, 11111, 111111};
    for (int i = 1; i <= 6; i++) {
        numbers[base[i] * N] = i;
        v.push_back(base[i] * N);
    }
    for (int it = 0; it < 8; it++) {
        const int size = v.size();
        for (int iti = 0; iti < size; iti++) {
            for (int itj = 0; itj < size; itj++) {
                const int i = v[iti], j = v[itj];
                if (numbers[i] + numbers[j] > 8) continue;
                int plus = i + j;
                int minus = i - j;
                int mult = i * j;
                int divide = i / j;

                if (plus > 0 && plus <= 32000)
                    numbers[plus] =
                        (numbers[plus] == -1)
                            ? (v.push_back(plus), numbers[i] + numbers[j])
                            : min(numbers[i] + numbers[j], numbers[plus]);
                if (minus > 0 && minus <= 32000)
                    numbers[minus] =
                        (numbers[minus] == -1)
                            ? (v.push_back(minus), numbers[i] + numbers[j])
                            : min(numbers[i] + numbers[j], numbers[minus]);
                if (mult > 0 && mult <= 32000)
                    numbers[mult] =
                        (numbers[mult] == -1)
                            ? (v.push_back(mult), numbers[i] + numbers[j])
                            : min(numbers[i] + numbers[j], numbers[mult]);
                if (divide > 0 && divide <= 32000)
                    numbers[divide] =
                        (numbers[divide] == -1)
                            ? (v.push_back(divide), numbers[i] + numbers[j])
                            : min(numbers[i] + numbers[j], numbers[divide]);
            }
        }
    }
    return numbers[number];
}

int main(void) {
    // freopen("input.txt", "r", stdin);
    int N, number;
    cin >> N >> number;
    memset(numbers, -1, sizeof(numbers));
    v.clear();
    cout << solution(N, number) << endl;
}