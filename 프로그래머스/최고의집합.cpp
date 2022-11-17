//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int n, int s) {
//    vector<int> answer;
//
//    if (s == 1 || n == 1)
//    {
//        answer.push_back(-1);
//        return answer;
//    }
//
//
//    while (n)
//    {
//        int num = s / n;
//        answer.push_back(num);
//        s -= num;
//
//        if (n == 1)
//            break;
//        n--;
//    }
//
//
//    return answer;
//}//처음 푼 코드 테스트케이스1개가 게속 걸렸다.

//예외처리 게속 틀려서 찾아봄

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }

    while (n)
    {
        int num = s / n;
        answer.push_back(num);
        s -= num;

        if (n == 1)
            break;
        n--;
    }

    return answer;
}