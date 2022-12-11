#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{

    stack<char> st;
    bool answer = true;

    for (int i = 0; i < s.size(); i++)
    {

        if (st.empty() && s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (st.empty() && s[i] == ')')
        {
            return false;
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }

    }
    return st.empty();
}