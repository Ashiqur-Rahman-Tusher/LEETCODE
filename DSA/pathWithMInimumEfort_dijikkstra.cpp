#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cmath>

using namespace std;

int minimumEffortPath(vector<vector<int>>& heights)
{
    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<int>> dist(rows,
                             vector<int>(cols, INT_MAX));

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    dist[0][0] = 0;

    pq.push({0,{0,0}});

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    while(!pq.empty())
    {
        int effort = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;

        pq.pop();

        if(r == rows-1 && c == cols-1)
            return effort;

        if(effort > dist[r][c])
            continue;

        for(int i=0;i<4;i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr<rows &&
               nc>=0 && nc<cols)
            {
                int w =
                abs(heights[nr][nc]
                    -
                    heights[r][c]);

                int newEffort =
                max(dist[r][c], w);

                if(newEffort < dist[nr][nc])
                {
                    dist[nr][nc] =
                    newEffort;

                    pq.push(
                    {
                        newEffort,
                        {nr,nc}
                    });
                }
            }
        }
    }

    return 0;
}

int main()
{
    vector<vector<int>> heights =
    {
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };

    cout << minimumEffortPath(heights);

    return 0;
}