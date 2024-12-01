#include<iostream>
using namespace std;

int main(){
    //initializations and declarations
    //char str[5]={'a','b','c','d','e'};

    int size;
    cin>>size;

    char str[size];

    for(int i=0;i<size;i++){
        cin>>str[i];
    }

    //O(1) access
    int val=str[2];

    // O(n) traverse
    for(int i=0;i<size;i++){
        cout<<str[i];
    }

    // O(n) insertion and

    // O(n) deletion
    
    return 0;
}
/*
Operation	Best	Average	Worst 
Access	    O(1)	O(1)	O(1)
Insertion	O(1)	O(n)	O(n)
Deletion	O(1)	O(n)	O(n)
Search(L)	O(1)	O(n)	O(n)
Compare Strings	O(1)	O(n)	O(n)
Concatenation	O(1)	O(n + m)	O(n + m)
Find Substring (Naive)	O(1)	O(n * m)	O(n * m)
Find Substring (KMP)	O(1)	O(n + m)	O(n + m)
*/