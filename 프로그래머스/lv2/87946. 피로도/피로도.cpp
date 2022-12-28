#include <string>
#include <vector>

using namespace std;

bool visited[8];
int answer = 0;
void dfsBackTracking(int energy ,int count ,const vector<vector<int>> dungeons)
{
    if(energy < 0 ) return;
    
    for(int i =0; i < dungeons.size(); i++)
    {
        if(!visited[i]&&energy>=dungeons[i][0])
        { //방문하지 않았고 최소 필요 피로도 조건 만족하면 이동
            visited[i] = true;
            dfsBackTracking(energy-dungeons[i][1], count+1,dungeons);
            visited[i] = false;
        }

    }
    answer = max(answer, count);
}

int solution(int k, vector<vector<int>> dungeons) {
    dfsBackTracking(k,0,dungeons);
    return answer;
}