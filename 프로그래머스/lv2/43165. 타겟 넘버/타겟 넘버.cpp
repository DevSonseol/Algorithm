#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;

void DFS(vector<int> numbers , const int target ,const int startIndex)
{
    vector<int> tempNumbers = numbers;
    int sum = 0;
    for(int i = 0 ; i < tempNumbers.size();i++)
        sum += tempNumbers[i];
    
    if(sum == target)
        answer++;
    
    for(int i = startIndex ; i < tempNumbers.size();i++)
    {
        if(tempNumbers[i] > 0)
        {
            tempNumbers[i] *= -1;
            DFS(tempNumbers,target,i);
            tempNumbers[i] *= -1;
        }

    }

}

int solution(vector<int> numbers, int target) {
    
    DFS(numbers,target,0);
    
    return answer;
}