#include <iostream>
#include <string>

using namespace std;
bool check(string input, int startIdx, int endIdx)
{

    if (startIdx >= endIdx)
    {
        return true;
    }
    int left = startIdx;
    int right = endIdx;

    while (left < right)
    {

        if (input[left++] == input[right--])
        {
            return false;
        }
    }
    return check(input, startIdx, right - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        string input;
        cin >> input;

        if (input.length() % 2 == 0)
        {
            cout << "NO\n";
            continue;
        }

        bool b = check(input, 0, input.length() - 1);

        if (b)
            cout << "YES\n";
        else
            cout << "NO\n";


    }
    return 0;
}
