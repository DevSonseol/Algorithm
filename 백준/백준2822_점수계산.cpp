#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int sum = 0;
	vector<pair<int, int> > vecScore;
	vector<int> number;

	for (int i = 1; i <= 8; ++i) {
		int num;
		cin >> num;
		vecScore.push_back({ num, i });
	}

	sort(vecScore.begin(), vecScore.end());

	for (int i = 3; i <= 7; ++i) {
		sum += vecScore[i].first;
		number.push_back(vecScore[i].second);
	}
	cout << sum << endl;

	sort(number.begin(), number.end());

	for (int i = 0; i < 5; ++i) {
		cout << number[i] << " ";
	}


	return 0;
}