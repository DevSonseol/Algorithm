#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 300

//���� ������
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

    //������� ���ϱ�
    boxes = min(n, m) / 2;

    //ȸ��
    while (r--) {
        int tmp[MAX][MAX];
        for (int i = 0; i < boxes; i++)
        {
            //������
            int x1 = i;
            int y1 = i;

            //����
            int x2 = n - 1 - i;
            int y2 = m - 1 - i;

            for (int i = y2 - 1; i >= y1; i--)
                tmp[x1][i] = board[x1][i + 1]; //��
            for (int i = x1 + 1; i <= x2; i++)
                tmp[i][y1] = board[i - 1][y1]; //��
            for (int i = y1 + 1; i <= y2; i++)
                tmp[x2][i] = board[x2][i - 1];//��
            for (int i = x2 - 1; i >= x1; i--)
                tmp[i][y2] = board[i + 1][y2];//�Ʒ�
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = tmp[i][j];
    }

    //���
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