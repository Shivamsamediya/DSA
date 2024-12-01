// O(n^2)
#include<iostream>
using namespace std;

int main(){
   int arr[5]={12,4,29,32,23};
   int n=5;

   //algo
   for(int i=1;i<n;i++){
      int j=i;
      while(j>0 && arr[j]<arr[j-1]){
         swap(arr[j],arr[j-1]);
         j--;
      }
   }
   //

   for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";

   return 0;
}