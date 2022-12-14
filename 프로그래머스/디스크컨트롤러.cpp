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

    sort(jobs.begin(), jobs.end(), compare); //�����ð� ������ �������� ����

    while (!jobs.empty())
    {
        for (int i = 0; i < jobs.size(); i++)  //�����ð� ���� ������ ��ȸ�ϸ鼭 
        {
            if (jobs[i][0] <= time)   // time���� ����ð��� ���ų� ���� �� Ž��
            {  //���� ���
                time += jobs[i][1];    
                answer += time - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }  
            if (i == jobs.size()-1) //���� ��� time����
                time++;

        }
    }

    return answer / n;
}