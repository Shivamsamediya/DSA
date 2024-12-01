///Vector
#include<iostream>
using namespace std;

int main(){
    int *arr = new int[5]{1,2,3,4,5};

    // O(1) access
    int val=arr[2];
    cout<<val;

    delete arr;//free memory allocated

    // O(n) insertion and

    // O(n) deletion  due to resizing

    return 0;
}