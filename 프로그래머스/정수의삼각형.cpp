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
    for (size_t f = 0; f < floor - 1; f++) // 총 층의 -1번까지
    {
        for (size_t i = 0; i <= f; i++) //해당층의 원소 갯수만큼
        {
            //왼쪽으로 
            left = dp[f][i] + triangle[f + 1][i];
            if (left > dp[f + 1][i]) //기존값보다 크다면 고침
                dp[f + 1][i] = left;

            //오른쪽으로
            right = dp[f][i] + triangle[f + 1][i + 1];
            if (right > dp[f + 1][i + 1]) //기존값보다 크다면 고침
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