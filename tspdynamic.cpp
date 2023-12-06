#include<iostream>
#include <vector>
using namespace std;

int tsp(vector<vector<int>> graph,vector<int> boolean,int n, int currentpos,int cost,int count,int ans){

    if(count ==n && graph[currentpos][0] > 0){
        ans = min(ans,cost+graph[currentpos][0]);
        return ans;
    }

    for(int i=0;i<n;i++){
        if(boolean[i] == 0 && graph[currentpos][i] > 0){
            boolean[i] = 1;

            ans = tsp(graph,boolean,n,i,cost+graph[currentpos][i],count+1,ans);

            boolean[i] = 0;
        }
    }
    return ans;
}

int main()
{
    int n=4;
    vector<vector<int>> graph{{0, 10, 15, 20},
                         {10, 0, 35, 25},
                         {15, 35, 0, 30},
                         {20, 25, 30, 0}};
    
    vector<int> boolean(n,0);
    int ans = INT32_MAX;
    boolean[0] = 1;
    ans = tsp(graph,boolean,n,0,0,1,ans);
    cout<<ans;
    return 0;
}