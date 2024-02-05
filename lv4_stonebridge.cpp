#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    vector<int> v(rocks);
    v.push_back(distance);
    v.push_back(0);
    sort(v.begin(), v.end());
    int l = 0, r = distance;
    while (l != r) {
        int mid = r - (r - l) / 2;
        int canRemove = n;
        int skipped = 0;
        int able = true;
        for (int i = 0; i < v.size() - 1; i++) {
            if (skipped + v[i + 1] - v[i] >= mid) {
                skipped = 0;
                continue;
            }
            if (canRemove == 0) {
                able = false;
                break;
            }
            skipped += v[i + 1] - v[i];
            canRemove--;
        }
        if (!able)
            r = mid - 1;
        else
            l = mid;
    }
    return r;
}
int main(void) { cout << solution(25, {2, 14, 11, 21, 17}, 2) << endl; }
