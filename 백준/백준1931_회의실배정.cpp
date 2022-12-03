#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, connect, cnt;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // 반복횟수 입력 받기
    cin >> n;

    // 시간 쌍 입력 받는 pair선언
    vector<pair<int, int>> p(n);

    // pair 입력 받기
    for (int i = 0; i < n; i++)
    {
        // pair를 sort하면 첫 번째 인자를 오름차순 정렬해서 두 번째 값을 정렬하기 위해 second와 first순서를 바꿔 입력 받음
        cin >> p[i].second >> p[i].first;
    }

    // 끝나는시간을 오름차순으로 정렬
    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        if (p[i].second >= connect) {
            connect = p[i].first;
            cnt++;
        }
    }

    cout << cnt;
}
