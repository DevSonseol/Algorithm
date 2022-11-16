#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> row;

        for (int j = 0; j < arr2.size(); j++)
        {
            int rowtemp = 0;
            for (int r = 0; r < arr1.size(); r++)
            {
                rowtemp += arr1[i][r] * arr2[r][j];
            }
            row.push_back(rowtemp);
        }
        answer.push_back(row);
    }

    return answer;
}