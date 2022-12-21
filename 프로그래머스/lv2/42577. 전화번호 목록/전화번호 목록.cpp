#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(),phone_book.end());
    
    for(int i = 0 ; i <phone_book.size()-1;i++ )
    {
        int index = phone_book[i+1].find(phone_book[i]);
        if(index ==0) return false;
    }

    return answer;
}