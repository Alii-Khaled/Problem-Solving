#include<iostream>
using namespace std;
#include<bits/stdc++.h>

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    int startColor = image[sr][sc];
    if(startColor == newColor) return image;
    
    int dRow[] = { -1, 0, 1, 0 };
    int dCol[] = { 0, 1, 0, -1 };
    
    queue<pair<int, int>> q;
    q.push({sr, sc});
    pair<int, int> cell;
    int cX, cY;
    int adjX, adjY;
    
    while(!q.empty()){
        cell = q.front();
        cX = cell.first;
        cY = cell.second;
        
        image[cX][cY] = newColor;
        q.pop();
        
        for(int i=0; i<4; i++){
            adjX = cX + dRow[i];
            adjY = cY +dCol[i];
            
            if(adjX < 0 || adjX >= image.size() || adjY < 0 || adjY >= image[0].size() || image[adjX][adjY] != startColor)
                continue;
            else{
                q.push({adjX, adjY});
            }
        }
    }
    return image;
}