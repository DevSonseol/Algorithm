#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    int up, down;

    for (int i = 0; i <= 10000; i++)
    {
        up = 0;
        down = 0;

        for (int j = 0; j < citations.size(); j++)
        {
            if (citations[j] <= i)
                down++;

            if (citations[j] >= i)
                up++;
        }

        if (up >= i && down <= i)
            answer = i;
    }

    return answer;
}