#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int maxAreaOfIsland(vector<vector<int>>& grid) {
    
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};
    
    queue<pair<int, int>> q;
    pair<int, int> cell;
    int cX, cY;
    int tempX, tempY;
    bool validCell;
    
    int tempArea = 0;
    int maxArea = 0;
    for(int x=0; x<grid.size(); ++x){
        for(int y=0; y<grid[0].size(); ++y){
            cout<<" ";
            if(grid[x][y] == 1){
                
                //BFS on (x, y):
                q.push({x, y});
                tempArea = 0;
                while(!q.empty()){
                    
                    cell = q.front();
                    cX = cell.first;
                    cY = cell.second;
                    grid[cX][cY] = 2;
                    
                    tempArea++;
                    q.pop();
                    cout<<","<<cX << "-" << cY;
                    for(int i=0; i<4; ++i){
                        tempX = cX + dRow[i];
                        tempY = cY + dCol[i];
                        validCell = tempX >= 0 && tempY >= 0 && tempX < grid.size() && tempY < grid[0].size() && grid[tempX][tempY] == 1;
                        if(validCell){
                            q.push({tempX, tempY});
                            grid[tempX][tempY] = 2;
                        }
                    }
                }
                maxArea = max(maxArea, tempArea);
                
            }
        }
    }
return maxArea;
}