#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < A.size(); i++)
    {
        answer += A[i] * B[i];
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << answer << endl;

    return answer;
}


////////////////////////////////////


//#include <iostream>
//#include<vector>
//#include <list>
//#include <algorithm>
//using namespace std;
//
//int solution(vector<int> A, vector<int> B)
//{
//    int answer = 0;
//
//    while (A.size()) {
//        //A의 최솟값 * B의 최댓값을 곱한 수를 answer에 더해주면 된다.
//        //계산후에 그값은 제거
//        int A_min = *min_element(A.begin(), A.end());
//        int B_Max = *max_element(B.begin(), B.end());
//
//        answer += A_min * B_Max;
//
//        A.erase(min_element(A.begin(), A.end()));
//        B.erase(max_element(B.begin(), B.end()));
//    }
//
//
//    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
//    cout << answer << endl;
//
//    return answer;
//}
