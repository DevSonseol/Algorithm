#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void Make_K_Arithmetic(string& str, const int n, const int k) {
    int number = n;

    if (number == 10)
        return;

    while (number >= k)
    {
        str = to_string(number % k) + str;
        number = number / k;
    }
    str = to_string(number) + str;
}

bool isPrimeNumber(long long number)
{
    if (number < 2) return false;

    for (int p = 2; p <= sqrt(number); p++)
    {
        if (number % p == 0)
            return false;
    }
    return true;

}

int solution(int n, int k) {
    int answer = 0;

    string str;
    Make_K_Arithmetic(str, n, k);
    str += '0';

    string temp;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '0')
            temp += str[i];
        else
        {
            if (temp.empty())
                continue;

            long long num = stoll(temp);

            if (isPrimeNumber(num))
                answer++;

            temp.clear();
        }
    }

    return answer;
}