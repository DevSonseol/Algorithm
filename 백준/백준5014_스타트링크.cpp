#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//º¯¼öµé
const int MAX = 1000001;
int F, S, G, U, D;
int path[MAX];
bool visited[MAX];
vector<int> dx;
queue<int> q;

void BFS(int f) {
    visited[f] = true;
    q.push(f);

    while (!q.empty()) {
        f = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int nextF = f + dx[i];

            if (0 < nextF && nextF <= F) {
                if (!visited[nextF]) {
                    visited[nextF] = true;
                    q.push(nextF);
                    path[nextF] = path[f] + 1;
                }
            }
        }

    }
}

int main() {
    cin >> F >> S >> G >> U >> D;

    dx.push_back(U);
    dx.push_back(D * -1);

    BFS(S);

    if (visited[G]) {
        cout << path[G];
    }
    else {
        cout << "use the stairs";
    }
}