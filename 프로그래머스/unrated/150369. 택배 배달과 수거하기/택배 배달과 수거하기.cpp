#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) 
{
    long long answer = 0;

    int start = -1;
    int idx = -1;
    int give = 0;
    int get = 0;
    for(int i=n-1 ;i>=0;--i)
    {
        if(deliveries[i]!=0 || pickups[i]!=0)
        {
            int cnt=0; //몇번 왕복해야 해당 I번재 배달 및 수거를 채우는가? 카운트
            while(give < deliveries[i] || get< pickups[i])
            {
                ++cnt;
                give+=cap;
                get+=cap;
            }
            //해당 번지 cnt 방문하는 동안 배달하고 수거 할 수 있는 물량 방문하면서 빼주기 
            give -= deliveries[i];
            get -=  pickups[i];
            answer = answer + (long long)((i+1)*cnt*2);
        }
    }
    return answer;
}