#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    vector<int> cards;
    int coin;
    int round;
};
struct cmp {
    bool operator()(Node& a, Node& b) { return a.round > b.round; }
};
pair<bool, bool> pick[4] = {
    {false, false}, {true, false}, {false, true}, {true, true}};

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    queue<Node> q;
    vector<int> currentCard = vector<int>(cards.begin(), cards.begin() + n / 3);
    cards = vector<int>(cards.begin() + n / 3, cards.end());
    Node node;
    node.cards = currentCard;
    node.coin = coin;
    node.round = 0;
    q.push(node);
    int answer = 0;
    while (!q.empty()) {
        Node tmp = q.front();
        q.pop();
        for (auto p : pick) {
            int tmpcoin = tmp.coin;
            vector<int> tmpcards = vector<int>(tmp.cards);
            if (pick->first)
                tmpcards.push_back(cards[tmp.round * 2]), tmpcoin--;
            if (pick->second)
                tmpcards.push_back(cards[tmp.round * 2 + 1]), tmpcoin--;
            if (tmpcoin >= 0) {
                for (int i = 0; i < tmpcards.size(); i++) {
                    for (int j = i + 1; j < tmpcards.size(); j++) {
                        if (tmpcards[i] + tmpcards[j] == n + 1) {
                            cout << tmpcards.size() << endl;
                            vector<int> tmptmpcards = vector<int>(tmpcards);
                            tmptmpcards.erase(tmptmpcards.begin() + j);
                            tmptmpcards.erase(tmptmpcards.begin() + i);
                            Node tmptmpnode;
                            tmptmpnode.cards = tmptmpcards;
                            tmptmpnode.coin = tmpcoin;
                            tmptmpnode.round = tmp.round + 1;
                            q.push(tmptmpnode);
                            answer = max(answer, tmptmpnode.round);
                        }
                    }
                }
            }
        }
    }
    return answer;
}

int main(void) {
    cout << solution(4, {3, 6, 7, 2, 1, 10, 5, 9, 8, 12, 11, 4}) << endl;
}