// O(n^2)
#include<iostream>
using namespace std;

int main(){
   int arr[5]={45,32,2,54,11};
   int n=5;

   //algo
   for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[mini]>arr[j]){
                mini=j;
            }
        }
        swap(arr[i],arr[mini]);
    }
    //

   for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";

   return 0;
}