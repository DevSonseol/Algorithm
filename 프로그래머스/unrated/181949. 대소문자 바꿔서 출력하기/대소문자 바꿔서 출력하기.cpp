#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    string answer;
    
    for(int i = 0 ; i < str.length() ; ++i)
    {
        char c = str[i];
        
        if(c >= 'Z')
        {
            c -=32;
            
        }else
        {
            c +=32;
        }
    
        answer+=c;
    }
    
    cout<<answer;
    
    return 0;
}