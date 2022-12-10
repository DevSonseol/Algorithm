#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int dp[100001];

int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    if (n == 1)
        return sticker[0];


    list<int> l;

    l.emplace_back

    //Ã¹¹øÂ°²¨ ¶âÀº°æ¿ì
    dp[0] = sticker[0];
    dp[1] = sticker[0];

    for (int i = 2; i < n - 1; i++)
    {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (answer < dp[i])
            answer = dp[i];
    }

    //µÎ¹øÂ°²¨ ¶âÀº°æ¿ì
    dp[0] = 0;
    dp[1] = sticker[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (answer < dp[i])
            answer = dp[i];
    }

    return answer;
}