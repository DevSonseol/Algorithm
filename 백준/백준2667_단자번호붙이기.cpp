#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 26

using namespace std;

//필요한 변수들
int n, cnt = 0;

string arr[MAX];
bool visited[MAX][MAX] = { 0 };

//왼 오 아래 위 순서로대로
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };
vector<int> result;
queue<pair<int, int>> q;

void bfs(int x, int y) {
    q.push({ x,y });
    visited[x][y] = true;
    cnt++;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = a + dirX[i];
            int nextY = b + dirY[i];
            if (0 <= nextX && 0 <= nextY && nextX < n && nextY < n && visited[nextX][nextY] == false
                && arr[nextX][nextY] == '1') {
                q.push({ nextX,nextY });
                visited[nextX][nextY] = true;
                cnt++;
            }
        }
    }
}


void DFS(int x, int y) {
    visited[x][y] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        if (0 <= nextX && 0 <= nextY && nextX < n && nextY < n &&
            visited[nextX][nextY] == false && arr[nextX][nextY] == '1') {
            DFS(nextX, nextY);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '1' && visited[i][j] == false) {
                cnt = 0;
                DFS(i, j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
