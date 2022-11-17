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
//}//ó�� Ǭ �ڵ� �׽�Ʈ���̽�1���� �Լ� �ɷȴ�.

//����ó�� �Լ� Ʋ���� ã�ƺ�

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