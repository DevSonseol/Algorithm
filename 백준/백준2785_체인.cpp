#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int cnt = 0;
    vector <int> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());


    while (v.size() != 1) {
        v[v.size() - 2] += v[v.size() - 1];
        v.pop_back();
        cnt++;
        v[0]--;

        if (v[0] == 0) {
            for (int i = 0; i < v.size() - 1; i++) {
                v[i] = v[i + 1];
            }
            v.pop_back();
        }
    }

    cout << cnt;

}