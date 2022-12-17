#include <string>
#include <vector>

using namespace std;

const int BigNumber = 999999;
int board[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = BigNumber;

    //보드 세팅
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            board[i][j] = BigNumber;
        }
        board[i][i] = 0;
    }

    for (int i = 0; i < fares.size(); i++)
    {
        board[fares[i][0]][fares[i][1]] = fares[i][2];
        board[fares[i][1]][fares[i][0]] = fares[i][2];
    }


    //플로이드 와샬 알고리즘
    for (int m = 0; m <= n; m++) //지나가는 중간
    {
        for (int i = 0; i <= n; i++) //시작
        {
            for (int j = 0; j <= n; j++)
            {
                if (board[i][j] > board[i][m] + board[m][j])
                    board[i][j] = board[i][m] + board[m][j];
            }
        }
    }


    for (int i = 0; i <= n; i++)
    {
        if (answer > board[s][i] + board[i][a] + board[i][b])
            answer = board[s][i] + board[i][a] + board[i][b];
    }

    return answer;
}