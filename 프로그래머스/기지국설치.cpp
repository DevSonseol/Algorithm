#include <iostream>
#include <vector>

using namespace std;

bool installed[200000001];

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int len = (2 * w) + 1;

    //�ϴ� installed�� ������ ���� ���� ǥ��
    for (auto st : stations)
    {
        //������
        installed[st] = 1;

        //W ��ŭ ���� ���� ���� ���� ǥ��
        for (int i = 1; i <= w; i++)
        {
            if (w == 0)
                break;

            if (st - i >= 1)
            {
                installed[st - i] = 1;
            }

            if (st + i <= n)
            {
                installed[st + i] = 1;
            }
        }

    }


    //���� installed ���鼭 ��ġ 
    for (int i = 1; i <= n;)
    {

        if (installed[i] == 0)
        {
            answer++;

            i += len;
        }
        else
        {
            i++;
        }

    }

    return answer;
}


//�������� ȿ���� �ɸ�

#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int len = (2 * w);
    int stNum = 0;

    for (int i = 1; i <= n; i++)
    {

        if (i >= stations[stNum] - w && i <= stations[stNum] + w)
        {
            i = stations[stNum] + w;
            stNum++;
        }
        else
        {
            answer++;
            i += len;
        }

    }

    return answer;
}