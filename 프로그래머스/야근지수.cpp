//#include <string>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//long long solution(int n, vector<int> works) {
//    long long answer = 0;
//
//    int size = works.size();
//    sort(works.begin(), works.end());
//
//    int total = 0;
//    for (int i = 0; i < size; i++) {
//        total += works[i];
//    }
//
//    if (n >= total)
//        return 0;
//
//    while (n--)
//    {
//        works[size - 1] -= 1;
//        sort(works.begin() , works.end());
//    }
//
//    for (int i = 0; i < works.size(); i++) {
//        answer += pow(works[i],2);
//    }
//
//    return answer;
//}//È¿À²¼º Å»¶ô

#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pq;
    int size = works.size();
    
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += works[i];
    }

    if (n >= total)
        return 0;


    for (int i = 0; i < size; i++) {
        pq.push(works[i]);
    }


    while (n--)
    {
        int temp = pq.top();
        pq.pop();
        pq.push(temp - 1);
    }

    while (!pq.empty())
    {
        int itop = pq.top();
        pq.pop();
        answer += itop * itop;
    }
 
    return answer;
}