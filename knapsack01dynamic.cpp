#include<iostream>
#include<vector>
using namespace std;
int recSol(vector<int> &weight,vector<int> &value,int n,int capacity){
    if(capacity == 0 || n==0){
        return 0;
    }

    if(weight[n-1]>capacity){
        return recSol(weight,value,n-1,capacity);
    }
    else{
        return max(value[n-1]+recSol(weight,value,n-1,capacity-weight[n-1]),recSol(weight,value,n-1,capacity));
    }
}


int dpSol(vector<int> &weight,vector<int> &value,int n,int capacity){

    //step 1 : 
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));

    //step 2: analyse base case
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0] <= capacity){
            dp[0][w]= value[0];
        }
        else{
            dp[0][w]=0; 
        }   
    }

    for(int index=1 ; index<n; index++){
        for(int w=0;w<=capacity;w++){
            int include=0;

            if(weight[index]<=w){
                include = value[index] + dp[index-1][w-weight[index]];
            }
            int exclude = 0 + dp[index-1][w];

            dp[index][w] = max(exclude,include);

        }
    }

    return dp[n-1][capacity];
}

int main()
{
    // int ans = 
    vector<int> value{60,100,120};
    vector<int> weight{10,20,30};
    int capacity = 40;
    int n = value.size();
    cout<< dpSol(weight,value,n,capacity)<<endl;
    cout<< recSol(weight,value,n,capacity);

    return 0;
} 