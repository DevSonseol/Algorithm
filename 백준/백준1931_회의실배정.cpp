#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, connect, cnt;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // �ݺ�Ƚ�� �Է� �ޱ�
    cin >> n;

    // �ð� �� �Է� �޴� pair����
    vector<pair<int, int>> p(n);

    // pair �Է� �ޱ�
    for (int i = 0; i < n; i++)
    {
        // pair�� sort�ϸ� ù ��° ���ڸ� �������� �����ؼ� �� ��° ���� �����ϱ� ���� second�� first������ �ٲ� �Է� ����
        cin >> p[i].second >> p[i].first;
    }

    // �����½ð��� ������������ ����
    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        if (p[i].second >= connect) {
            connect = p[i].first;
            cnt++;
        }
    }

    cout << cnt;
}
