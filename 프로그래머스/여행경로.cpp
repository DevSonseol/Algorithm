#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> answer; //��� ���� �� answer
bool visited[10001]; //Ƽ�� �� �� ǥ��
bool flag = false; //��� ��ȸ �ߴ��� üũ�� bool
int cnt; //ī��Ʈ


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
    return answer;
}