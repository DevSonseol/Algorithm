#include <iostream>
#include <vector>

using namespace std;

bool installed[200000001];

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int len = (2 * w) + 1;

    //일단 installed에 기지국 전파 범위 표기
    for (auto st : stations)
    {
        //기지국
        installed[st] = 1;

        //W 만큼 좌측 우측 전파 범위 표기
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


    //이제 installed 보면서 설치 
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


//위에꺼는 효율성 걸림

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