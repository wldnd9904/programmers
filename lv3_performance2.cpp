#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Node {
   public:
    int A;
    int B;
    Node* left;
    Node* right;
} Node;
Node* newNode(int A, int B) {
    Node* N = new Node;
    N->A = A;
    N->B = B;
    N->left = NULL;
    N->right = NULL;
    return N;
}
Node* tree;
void enTree(Node* n) {
    Node* current = tree;
    while (true) {
        // A비교
        if (n->A >= current->A) {
            if (current->right == NULL) {
                current->right = n;
                return;
            } else {
                current = current->right;
            }
        } else {
            if (current->left == NULL) {
                current->left = n;
                return;
            } else {
                current = current->left;
            }
        }
        // B 비교
        if (n->B >= current->B) {
            if (current->right == NULL) {
                current->right = n;
                return;
            } else {
                current = current->right;
            }
        } else {
            if (current->left == NULL) {
                current->left = n;
                return;
            } else {
                current = current->left;
            }
        }
    }
}

bool isDdait(int A, int B, Node* current,
             bool round) {  // round: true, false, true, false, ...
    if (current == NULL) return false;
    if (current->A > A && current->B > B) return true;
    if (round) {
        // A비교
        if (A >= current->A) {
            return isDdait(A, B, current->right, false);
        } else {
            return isDdait(A, B, current->right, false) ||
                   isDdait(A, B, current->left, false);
        }
    } else {
        // B 비교
        if (B >= current->B) {
            return isDdait(A, B, current->right, true);
        } else {
            return isDdait(A, B, current->right, true) ||
                   isDdait(A, B, current->left, true);
        }
    }
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    vector<vector<int>>::iterator it = scores.begin();
    vector<int> wanho = (*it);
    tree = newNode(wanho[0], wanho[1]);
    int rank[200001];
    memset(rank, 0, sizeof(rank));
    int wanhos = wanho[0] + wanho[1];
    for (++it; it != scores.end(); it++) {
        vector<int> candi = (*it);
        if (candi[0] + candi[1] > wanhos) {
            Node* candiNode = newNode(candi[0], candi[1]);
            enTree(candiNode);
        }
    }
    it = scores.begin();
    if (isDdait(wanho[0], wanho[1], tree, true)) return -1;
    for (++it; it != scores.end(); it++) {
        vector<int> candi = (*it);
        if (candi[0] + candi[1] > wanhos) {
            if (!isDdait(candi[0], candi[1], tree, true)) {
                rank[candi[0] + candi[1]]++;
            }
        }
    }
    for (int i = 200000; i > wanhos; i--) {
        answer += rank[i];
    }
    return answer + 1;
}

int main(void) {
    vector<vector<int>> scores = {{2, 2}, {1, 4}, {3, 2}, {3, 2}, {2, 1}};
    cout << solution(scores) << endl;
    return 0;
}