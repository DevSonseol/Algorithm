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

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
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
//        //A�� �ּڰ� * B�� �ִ��� ���� ���� answer�� �����ָ� �ȴ�.
//        //����Ŀ� �װ��� ����
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
//    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
//    cout << answer << endl;
//
//    return answer;
//}
