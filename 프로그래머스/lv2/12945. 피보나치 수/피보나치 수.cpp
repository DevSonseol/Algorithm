#include <iostream>
#include <string>
#include <vector>


using namespace std;

long long fibo[100001];

int solution(int n) {
    int answer = 0;
    
    fibo[1] = 1;
    
    for(int i = 0; i < 100001; i++)
    {
        fibo[i+2] = (fibo[i] + fibo[i+1])%1234567;
    }

    answer = fibo[n];
    
    return answer;
}