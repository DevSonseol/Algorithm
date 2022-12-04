#include<iostream>
#include<string>

using namespace std;

const int mod = 1000000;

int main() {
    string s; cin >> s;
    int size = s.size();

    //����ó��
    if (s[0] == '0') {
        cout << 0; return 0;
    }

    // dp�� 0,1��° ���� 1
    int dp[5001] = { 1,1 };
    for (int i = 2; i <= size; i++) {
        if (s[i - 1] > '0')
            dp[i] = dp[i - 1] % mod; //s�� ���簪(i-1)�� 0�� �ƴ� ��

        int n = (s[i - 2] - '0') * 10 + s[i - 1] - '0'; //s[i-2 ~ i-1]�� 10~26�� ��
        if (10 <= n && 26 >= n) {
            dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
    }

    cout << dp[size];
}