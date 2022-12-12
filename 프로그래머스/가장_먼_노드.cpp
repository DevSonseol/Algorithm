#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int dp[20001];
bool board[20001][20001];

int num;
int cost;
void BFS()
{
    queue<int> q;
    q.push(1);
    dp[1] = 0;

    while (!q.empty())
    {
        int next = q.front();
        q.pop();

        for (int i = 2; i <= num; i++)
        {
            if (board[next][i] == 1 && dp[i] == 0)
            {
                dp[i] = dp[next] + 1;
                q.push(i);
                cost = max(dp[i], cost);
            }
        }
    }

}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    num = n;
    vector<int> v(n);

    for (auto e : edge)
    {
        board[e[0]][e[1]] = 1;
        board[e[1]][e[0]] = 1;
    }

    BFS();

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == cost) answer++;
    }


    return answer;
}