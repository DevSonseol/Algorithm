#include <string>
#include <vector>
#include <iostream>

using namespace std;

int board[100][100];
bool ch[100];

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    fill(&board[0][0], &board[99][99], 9999);

    for (auto cost : costs)
    {
        board[cost[0]][cost[1]] = cost[2];
        board[cost[1]][cost[0]] = cost[2];
    }


    int minCost = 9999;
    int chNum = 0;
    ch[0] = true;

    for (int j = 0; j < n; j++)
    {
        if (board[0][j] < minCost)
        {
            minCost = board[0][j];
            chNum = j;
        }
    }

    answer += minCost;
    ch[chNum] = true;

    cout << 0 << ":" << minCost << endl;

    for (int i = 0; i < n; i++)
    {
        if (ch[i])
            continue;

        minCost = 9999;
        chNum = 0;
        for (int j = 0; j < n; j++)
        {

            if (board[i][j] < minCost)
            {
                minCost = board[i][j];
                chNum = j;
            }
        }
        ch[chNum] = true;

        answer += minCost;

        cout << i << ":" << minCost << endl;
    }


    return answer;
}

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int set[101];   // node의 parent를 저장하는 배열

int getParent(int node) {
    if (set[node] == node) return node;

    return set[node] = getParent(set[node]);
}

bool compareCost(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (int i = 0; i < n; i++)
        set[i] = i;

    sort(costs.begin(), costs.end(), compareCost);  // 비용을 오름차순 정렬

    for (int i = 0; i < costs.size(); i++) {
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];

        if (start != end) {  // cycle이 만들어지지 않을 경우 다리를 추가
            answer += cost;
            set[end] = start;
        }
    }

    return answer;
}
