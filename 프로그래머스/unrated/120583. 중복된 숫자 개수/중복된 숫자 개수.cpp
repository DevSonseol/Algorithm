#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    for(int i = 0 ; i < array.size(); ++i)
    {
        if( n == array[i])
            answer++;
    }
    return answer;
}