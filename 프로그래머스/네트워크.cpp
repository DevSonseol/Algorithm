#include <string>
#include <vector>
using namespace std;

bool visited[201];
int num = 0;

void dfs(int x, const vector<vector<int>>& computers)
{
    visited[x] = true;

    for (int i = 0; i < num; i++) {
        if (computers[x][i] == 1 && visited[i] == false) {
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    num = n;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            answer++;
            dfs(i, computers);
        }
    }

    return answer;
}