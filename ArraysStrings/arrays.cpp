#include<iostream>
using namespace std;

int main(){
    //declaraction and initialization.
    
    //1.
    // int arr[5]={1,2,3,4,5};

    //2.
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    // --> i=index of element <--

    //O(n)--traverse
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";


    // O(1)--access
    //int val= arr[i] ;


    /*
    O(n)--insertion
    int arr[6] = {1, 2, 3, 4, 5};
    int n = 5;

    int index = 2;
    int newValue = 10;

    // Shift elements to the right
    for (int i = n; i > index; i--) {
       arr[i] = arr[i - 1];
    } 

    arr[index] = newValue;  // Insert new value
    n++;
    */
    
    /* 
    O(n)--deletion
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    int index = 2;

    // Shift elements to the left
    for (int i = index; i < n - 1; i++){
      arr[i] = arr[i + 1];
    }
    n--;
    */
    return 0;
}

/*
Arrays--
Operation	Best Average	Worst Case
Access	  O(1)	O(1)	    O(1)
Insertion	O(1)	O(n)	    O(n)
Deletion	O(1)	O(n)	    O(n)
Search(L)	O(1)	O(n)	    O(n)
Search(B)	O(1)	O(log n)	O(log n)

*/


/*
2D arrays--
Operation	Best	Average	Worst Case
Access	  O(1)	 O(1)	    O(1)
Insertion	O(1)	O(n * m)	O(n * m)
Deletion	O(1)	O(n * m)	O(n * m)
Search(L)	O(1)	O(n * m)	O(n * m)
Search(B)	O(1)	O(n * log m)	O(n * log m) Row wise sorted
Search(B)	O(1)	O(log(n * m))	O(log(n * m)) Fully sorted
--
Mat Multi O(n * m * p)	O(n * m * p)	O(n * m * p)
Transpose O(n * m)	O(n * m)	O(n * m)
Row/Col Sum O(m)/O(n)	O(m)/O(n)	O(m)/O(n)
*/