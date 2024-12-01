// O(n^2)
#include<iostream>
using namespace std;

int main(){
   int arr[5]={19,23,3,15,27};
   int n=5;

   //algo
   for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    //

   for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";

   return 0;
}