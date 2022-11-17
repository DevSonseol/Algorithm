#include <string>
#include <vector>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    size_t floor = triangle.size();

    dp[0][0] = triangle[0][0];
    size_t left = 0;
    size_t right = 0;
    for (size_t f = 0; f < floor - 1; f++) // �� ���� -1������
    {
        for (size_t i = 0; i <= f; i++) //�ش����� ���� ������ŭ
        {
            //�������� 
            left = dp[f][i] + triangle[f + 1][i];
            if (left > dp[f + 1][i]) //���������� ũ�ٸ� ��ħ
                dp[f + 1][i] = left;

            //����������
            right = dp[f][i] + triangle[f + 1][i + 1];
            if (right > dp[f + 1][i + 1]) //���������� ũ�ٸ� ��ħ
                dp[f + 1][i + 1] = right;
        }
    }

    for (int i = 0; i < floor; i++)
    {
        if (answer < dp[floor - 1][i])
            answer = dp[floor - 1][i];
    }

    return answer;
}