// O(n) LS
#include<iostream>
using namespace std;

bool linearSearch(int key,int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==key) return true;
    }
    return false;
}
int main(){
   int arr[5]={15,20,30,45,60};
   int key;
   int n=5;
   cin>>key;
   bool ans=linearSearch(key,arr,n);

   if(ans)cout<<"Element found in arr";
   else cout<<"Element not found in arr";

   return 0;
}