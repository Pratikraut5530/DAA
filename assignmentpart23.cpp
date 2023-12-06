#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

int partition(vector<int> &arr,int start,int end){
    int pivot = arr[start];

    int cnt=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    //placing pivot at right placce
    int pivotIndex = start + cnt;
    swap(arr[pivotIndex],arr[start]);

    //arranging the left and right part
    int i = start,j=end;
    while(i<pivotIndex && j>pivotIndex){

        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] >  pivot){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;  
}


void quicksort(vector<int> arr,int start,int end){
    if(start < end){
        int pIndex = partition(arr,start,end);
        quicksort(arr,start,pIndex-1);
        quicksort(arr,pIndex+1,end); 
    }
}

int main()
{
    vector<int> arr{3,2,1,9,6,11};

    int n = arr.size();

    auto s = clock();
    quicksort(arr, 0, arr.size()-1);
    auto e = clock();
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    auto time_req = e-s;
    
    cout<<"Time required: "<<time_req<<"ms"<<std::endl;
    return 0;
}