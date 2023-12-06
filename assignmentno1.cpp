#include<iostream>
using namespace std;

bool binarySearch(int arr[],int size,int key){
    int start  = 0;
    int end = size - 1;

    int mid = start + (end - start)/2;

    while(start<=end){
        if(arr[mid] == key){
            return true;
        }
        if(key > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end - start)/2;
    }

    return false;
}

int main()
{
    cout<<"Hello World"<<endl;
    int arr[5]={1,2,3,4,5};
    bool ans = binarySearch(arr,5,21);

    if(ans){
        cout<<"Key is present"<<endl;
    }
    else{
        cout<<"Key is absent"<<endl;
    }
    return 0;
}