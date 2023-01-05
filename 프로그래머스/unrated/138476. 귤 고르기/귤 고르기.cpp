#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

int solution(int k, vector<int> tangerine) {
    int answer = 0, cnt = 0;
    map<int,int> m;
    map<int,int>::iterator iter;
    vector<vector<int> > v;

    for(int i=0; i<tangerine.size(); i++)
        m[tangerine[i]]++;
    for(iter = m.begin(); iter != m.end(); iter++) {
        vector<int> tmp(2);
        tmp[0] = iter->first, tmp[1] = iter->second;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), compare);

    for(int i=0; i<v.size(); i++) {
        cnt += v[i][1];
        answer++;
        if(cnt >= k) break;
    }

    return answer;
}
