#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;

	while (a != b)
	{
		int aRemainer = a / 2;
		int aShare = a % 2;

		int bRemainer = b / 2;
		int bShare = b % 2;

		a = aRemainer + aShare;
		b = bRemainer + bShare;

		answer++;
	}
	//testasd
	return answer;
}