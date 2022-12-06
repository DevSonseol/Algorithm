#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool jadenCase = true;

string solution(string s) {

    string answer = s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            jadenCase = true;
            continue;
        }

        if (jadenCase)
        {
            jadenCase = false;
            if (answer[i] >= 'a' && answer[i] <= 'z')
                answer[i] -= 32;
        }
        else
        {
            if (answer[i] >= 'A' && answer[i] <= 'Z')
                answer[i] += 32;
        }
    }

    return answer;
}