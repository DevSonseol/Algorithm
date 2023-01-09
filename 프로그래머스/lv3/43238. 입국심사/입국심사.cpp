#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long left = 1;
    long long right = (long long)times[times.size() -1] * n;

    while(left <= right){
        long long mid = (left + right) / 2;

        long long cnt = 0; //mid 시간동안 심사 받을 수  있는 사람의 수
        for(unsigned int i=0; i<times.size(); i++){
            //각 심사대에서 mid 시간동안 심사 받을 수 있는 사람의 수 누적하기
            cnt += mid / times[i]; 
        }

        if(cnt < n){ //심사받아야 하는 사람이 남은 경우
            left = mid + 1;
        } else{ //n명이상 심사받은 경우
            answer = mid;
            right = mid - 1;
        }
    }
    return answer;
}