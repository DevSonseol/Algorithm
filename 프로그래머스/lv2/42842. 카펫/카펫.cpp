#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;

    
    for(int i = 3 ; i <= total/3 + 1 ; i++)
    {
        int x,y;
        x= i-2;
        y= (total/i -2);
        
        
        if( x * y == yellow) 
        {
            answer.push_back(total/i);
            answer.push_back(i);
            break;
        }
    }
    
    return answer;
}