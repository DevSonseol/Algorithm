#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int time =0;
    int highest = 0;
    
  
		for (int i = 0; i< prices.size() - 1; i++)
		{
			time = 0;
            highest = prices[i];
			for (int j = i + 1; j< prices.size(); j++)
			{
				if ( highest  <= prices[j])
                    time++;
                else
                {
                   time++;
                   break;
                }
			}

			answer.push_back(time);
		}

		answer.push_back(0);



    
    return answer;

}