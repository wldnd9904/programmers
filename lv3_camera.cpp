#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (int i = 0; i < routes.size(); i++) {
        pq.push({routes[i][0], routes[i][1]});
    }
    int flag = pq.top().second;
    int answer = 1;
    while (!pq.empty()) {
        pair<int, int> route = pq.top();
        pq.pop();
        // cout << route.first << ',' << route.second << endl;
        if (route.second < flag) flag = route.second;
        if (route.first > flag) {
            flag = route.second;
            answer++;
        }
    }
    return answer;
}

int main(void) {
    cout << solution({{-20, -15}, {-14, -5}, {-18, -13}, {-5, -3}}) << endl;
}
