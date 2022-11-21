#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    deque<int> dq;
    deque<int>::iterator iter;

    bool in = false;

    int len = operations.size();
    for (int i = 0; i < len; i++)//operations크기만큼 수행
    {
        string str = operations[i];
        string sub = operations[i].substr(2);


        if (operations[i][0] == 'I') {

            int n = atoi(sub.c_str());

            in = false;

            if (dq.empty()) {
                dq.push_back(n);
            }
            else
            {
                for (iter = dq.begin(); iter != dq.end(); iter++) {

                    if (n < *iter)
                    {
                        dq.insert(iter, n);
                        in = true;
                        break;
                    }
                }

                if (!in)
                    dq.push_back(n);

            }

        }
        else {// D 일때

            if (sub == "-1") {
                if (!dq.empty())
                    dq.pop_front();
            }
            else
            {
                if (!dq.empty())
                    dq.pop_back();
            }

        }

    }

    //출력
    if (dq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }

    return answer;
}