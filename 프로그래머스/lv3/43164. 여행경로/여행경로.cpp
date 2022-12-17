#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> answer; //경로 저장 할 answer
bool visited[10001]; //티켓 쓴 거 표시
bool flag = false; //모두 순회 했는지 체크할 bool
int cnt; //카운트

void DfS(string cur, const vector<vector<string>> tickets)
{
    if (cnt == tickets.size()) flag = true;

    answer.emplace_back(cur);

    for (int i = 0; i < tickets.size(); i++)
    {
        if (!visited[i] && tickets[i][0] == cur)
        {
            visited[i] = true;
            cnt += 1;
            DfS(tickets[i][1], tickets);

            //backtracking
            if (!flag)
            {
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    DfS("ICN", tickets);
    int i = 0;
        int i2 =2 ;
    return answer;
}