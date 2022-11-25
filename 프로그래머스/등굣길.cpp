#include <string>
#include <vector>

using namespace std;

int board[101][101]; //ĭ���� ��� �������� ǥ���� 

int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

void dfs(int x, int y, const int destX, const int destY, const vector<vector<int>> puddles) {

    if (x == destX && y == destY)
        return;

    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx > destX || ny > destY || board[nx][ny] == -1) continue;

        dfs(nx, ny, destX, destY, puddles);
        board[nx][ny]++;
    }

}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    for (int i = 0; i < puddles.size(); i++)
    {
        board[puddles[i][1]][puddles[i][0]] = -1; //���������°����� ǥ��
    }

    dfs(1, 1, n, m, puddles);

    return board[n][m] % 1000000007;
}
///////ȿ�������� �ɸ�

#include <string>
#include <vector>

using namespace std;

int dx[2] = { 0,-1 };
int dy[2] = { -1,0 };
int dp[101][101]; //���������� �ڵ����� 0���� �ʱ�ȭ��
int divnum = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    for (int i = 0; i < puddles.size(); i++) {
        dp[puddles[i][1]][puddles[i][0]] = -1; //���������°����� ǥ��
    }

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) { //  
        for (int j = 1; j <= m; j++) { //  
            if (dp[i][j] == -1) continue;
            for (int k = 0; k < 2; k++) {

                int x = i + dx[k];
                int y = j + dy[k];

                if (dp[x][y] == -1) continue;
                dp[i][j] += dp[x][y];
            }
            dp[i][j] %= 1000000007;
        }
    }

    return dp[n][m];
}