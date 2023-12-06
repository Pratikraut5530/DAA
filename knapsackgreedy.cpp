#include<iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
struct Item{
    int value;
    int weight;
};

static bool cmp(pair<double,Item> a,pair<double,Item> b){
    return a.first > b.first;
}

double fractionalknapsack(int W,Item arr[],int n){
    vector<pair<double,Item>> v;

    for(int i=0;i<n;i++){
        double perunitvalue = (1.0*arr[1].value)/arr[i].weight;
        pair<double,Item> p = make_pair(perunitvalue,arr[i]);
        v.push_back(p);
    }

    sort(v.begin(),v.end(),cmp);

    double totalValue = 0;
    for(int i=0;i<n;i++){
        if(v[i].second.weight > W){
            // can only take fraction of itt
            totalValue += W*v[i].first;
            W =0;
        }
        else{
            totalValue += v[i].second.value;
            W = W - v[i].second.weight;
        }
    } 

    return totalValue;
}

int main()
{
    int W = 20; 
    Item arr[] = { { 10, 3 }, { 20, 5 }, { 21, 5 }, { 30, 8 }, { 16, 4 } };
 
    int N = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Maximum value we can obtain = "<< fractionalknapsack(W, arr, N);
    return 0;
}