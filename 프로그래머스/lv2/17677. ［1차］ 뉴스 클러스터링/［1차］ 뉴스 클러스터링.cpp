#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

const int multiNum = 65536;

void MakeMap(map<string, int>& m, string str, set<string>& s)
{
    //str 일단 소문자 대문자로 변환
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }

    for (int i = 0; i < str.length() - 1; i++)
    {
        string tempStr;
        if (str[i] >= 'A' && str[i] <= 'Z' && str[i + 1] >= 'A' && str[i + 1] <= 'Z')
        {
            tempStr += str[i];
            tempStr += str[i + 1];
            m[tempStr]++;
            s.insert(tempStr);
        }
    }
}

int solution(string str1, string str2) {
    float intersectionCnt = 0;
    float unionCnt = 0;
    map<string, int> m1;
    map<string, int> m2;

    set<string> s;

    //str1 , str2 각 각 다중집합으로 만들기
    MakeMap(m1, str1, s);
    MakeMap(m2, str2, s);

    for (auto iter : s)
    {
        intersectionCnt += min(m1[iter], m2[iter]);
        unionCnt += max(m1[iter], m2[iter]);
    }

    if (intersectionCnt == 0 && unionCnt == 0)
        return multiNum;

    return (intersectionCnt / unionCnt) * multiNum;
}