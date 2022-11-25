//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//bool visited[50];
//
//string targetword;
//int answer = 0;
//bool same = false;
//
//bool OneWordDifferent(string a, string b)
//{
//    int count = 0;
//
//    for (int i = 0; i < a.size(); i++)
//    {
//        if (a[i] != b[i])
//            count++;
//    }
//
//    return (count == 1) ? true : false;
//
//}
//
//
//void dfs(string& word, const vector<string> words)
//{
//
//    answer++;
//    cout << word;
//
//    if (OneWordDifferent(word, targetword))
//    {
//        answer++;
//        word = targetword;
//        same = true;
//        cout << word;
//        return;
//    }
//
//
//    int i;
//    for (i = 0; i < words.size(); i++)
//    {
//        if (same)
//            break;
//
//        if (OneWordDifferent(word, words[i]) && visited[i] == false)
//        {
//            word = words[i];
//            visited[i] = true;
//            dfs(word, words);
//        }
//    }
//
//    if (i == words.size())
//        return;
//}
//
//int solution(string begin, string target, vector<string> words) {
//    targetword = target;
//
//    if (find(words.begin(), words.end(), target) == words.end()) { // vector내에 target이 존재하지 않음
//        return answer;
//    }
//
//
//    for (int i = 0; i < words.size(); i++)
//    {
//        //초기화
//        string temp = begin;
//        answer = 0;
//        for (int v = 0; v < 50; v++)
//            visited[v] = false;
//
//        ////////////////////탐색
//
//        if (OneWordDifferent(temp, words[i]))
//        {
//            temp = words[i];
//            visited[i] = true;
//            dfs(temp, words);
//        }
//
//        if (same)
//        {
//            return answer;
//        }
//    }
//
//    return answer;
//}


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[50];
int answer = 50;

bool OneWordDifferent(string a, string b)
{
    int count = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            count++;
    }

    return (count == 1) ? true : false;

}


void dfs(string word, const string target, const vector<string> words, int step)
{
    if (answer <= step)
        return;

    if (word == target) {
        answer = min(answer, step);
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        // 한개의 문자만 다르고 방문 하지 않은 단어이면 탐색 시작
        if (OneWordDifferent(word, words[i]) && !visited[i]) {
            visited[i] = true;
            // 그 단어부터 탐색을 다시 시작한다. 단계가 하나 추가되었으므로 step+1을 인자로 넘긴다.
            dfs(words[i], target, words, step + 1);
            // dfs 재귀 호출하여 종료되어 여기로 돌아오면, 백트래킹 (방문 표시 해제) 하여 다음분기점부터 다시 탐색을 시작한다.
            visited[i] = false;
        }

    }
    return;
}


int solution(string begin, string target, vector<string> words) {

    dfs(begin, target, words, 0);

    if (answer == 50)
        return 0;

    return answer;
}


