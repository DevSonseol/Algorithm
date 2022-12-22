#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    map<string, int> m;
    //알파벳 map에 순서대로 입력
    for (int i = 0; i < 26; i++)
    {
        string s;
        s += ('A' + i);
        m.insert(make_pair(s, i + 1));
    }

    string nowStr;
    string nextStr;
    string temp;

    nowStr = msg[0];
    nextStr = msg[1];
    for (int i = 1; i < msg.length(); i++)
    {

        temp = nowStr + nextStr;
        cout<<temp<<endl;
        
        if (m.find(temp) != m.end()) //있을 경우
        {
            //answer.emplace_back(999);
            //answer.emplace_back(m[temp]);
            nowStr = temp;
            nextStr = msg[i + 1];
        }
        else //없을 경우
        {
            answer.emplace_back(m[nowStr]);
            m.insert(make_pair(temp, m.size() + 1));
            nowStr = nextStr;
            nextStr = msg[i + 1];

        }
    }
    answer.emplace_back(m[nowStr]);



    for (auto ele : m)
    {
       //cout << ele.first << ele.second << endl;
    }

    return answer;
}