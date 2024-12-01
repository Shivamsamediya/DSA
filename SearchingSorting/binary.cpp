//O(logn) BS
#include<iostream>
using namespace std;

bool binarySearch(int s,int e,int arr[],int key){
    int mid= s+(e-s)/2;

    while(s<=e){
        
        if(arr[mid]==key) return true;
        else if(arr[mid]>key) e=mid-1;
        else s=mid+1;

        mid=s+(e-s)/2;
    }
    return false;
}

int main(){
   int arr[5]={15,20,30,45,60};
   int key,n=5;
   cin>>key;
   int s=0,e=n-1;
   bool ans = binarySearch(s,e,arr,key);

   if(ans)cout<<"Element found in arr";
   else cout<<"Element not found in arr";

   return 0;
}