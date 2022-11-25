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
//    if (find(words.begin(), words.end(), target) == words.end()) { // vector���� target�� �������� ����
//        return answer;
//    }
//
//
//    for (int i = 0; i < words.size(); i++)
//    {
//        //�ʱ�ȭ
//        string temp = begin;
//        answer = 0;
//        for (int v = 0; v < 50; v++)
//            visited[v] = false;
//
//        ////////////////////Ž��
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
        // �Ѱ��� ���ڸ� �ٸ��� �湮 ���� ���� �ܾ��̸� Ž�� ����
        if (OneWordDifferent(word, words[i]) && !visited[i]) {
            visited[i] = true;
            // �� �ܾ���� Ž���� �ٽ� �����Ѵ�. �ܰ谡 �ϳ� �߰��Ǿ����Ƿ� step+1�� ���ڷ� �ѱ��.
            dfs(words[i], target, words, step + 1);
            // dfs ��� ȣ���Ͽ� ����Ǿ� ����� ���ƿ���, ��Ʈ��ŷ (�湮 ǥ�� ����) �Ͽ� �����б������� �ٽ� Ž���� �����Ѵ�.
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


