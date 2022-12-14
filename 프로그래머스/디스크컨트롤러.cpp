#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    int time = 0;

    sort(jobs.begin(), jobs.end(), compare); //업무시간 순으로 오른차순 정렬

    while (!jobs.empty())
    {
        for (int i = 0; i < jobs.size(); i++)  //업무시간 적은 순으로 순회하면서 
        {
            if (jobs[i][0] <= time)   // time보다 실행시간이 적거나 같은 잡 탐색
            {  //있을 경우
                time += jobs[i][1];    
                answer += time - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }  
            if (i == jobs.size()-1) //없을 경우 time증가
                time++;

        }
    }

    return answer / n;
}