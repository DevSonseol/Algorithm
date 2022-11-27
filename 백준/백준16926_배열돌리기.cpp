#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 300

//받을 변수들
int n, m;
int r, RotateCircle;
int boxes;
int board[MAX][MAX] = { 0 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    //몇겹인지 구하기
    boxes = min(n, m) / 2;

    //회전
    while (r--) {
        int tmp[MAX][MAX];
        for (int i = 0; i < boxes; i++)
        {
            //시작점
            int x1 = i;
            int y1 = i;

            //끝점
            int x2 = n - 1 - i;
            int y2 = m - 1 - i;

            for (int i = y2 - 1; i >= y1; i--)
                tmp[x1][i] = board[x1][i + 1]; //위
            for (int i = x1 + 1; i <= x2; i++)
                tmp[i][y1] = board[i - 1][y1]; //왼
            for (int i = y1 + 1; i <= y2; i++)
                tmp[x2][i] = board[x2][i - 1];//오
            for (int i = x2 - 1; i >= x1; i--)
                tmp[i][y2] = board[i + 1][y2];//아래
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = tmp[i][j];
    }

    //출력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}