// Name = Dheeraj Batra Sid = 21104030 Branch = EE

Ques1=What is the difference between in-place and out-place sorting algorithms?
Ans: IN-PLACE ALGORITHMS:
1)An in-place algorithm transforms the input without using any extra memory. As the algorithm executes, the input gets updated by the output, and no additional space 
is needed for this operation.
2)An in-place algorithm may require a small amount of extra memory for its operation.But this space is independent of input size and is constant
3)Examples are: bubble sort , heap sort , insertion sort , quick sort , selection sort

OUT-PLACE ALGORITHMS:
1)An algorithm that is not in-place is called a not-in-place or out-of-place algorithm. Unlike an in-place algorithm, the extra space used by an out-of-place algorithm
depends on the input size.
3)Standard merge sort algorithm is an example of out-of-place algorithm as it requires O(n) extra space for merging. The merging can be done using in-place also but 
it will increase the time complexity of sorting.
2)Example are: radiax sort , merge sort

Ques2=Implement Insertion sort in both (in-place and out-place) manner.
Ans: the basic difference in the code of inplace and outplace is just that in inplace we used the same array we gave in input and performed operations on it whereas in 
case of outplace we gave another piece of array named as arr1 and performed all operations on it; 

#include <iostream>
using namespace std;

// 1)Insertion sort using IN-PLACE ALGORITHM
void insertion_sort_IP(int arr[], int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}

// 2)Insertion sort using OUT-PLACE ALGORITHM
void insertion_sort_OP(int arr[],int arr1[],int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr1[j+1]=current;
    }
}

// function used to print the elements of array
void print(int arr[],int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" "; 
}

int main(){
    int n;
    cout<<"enter the size of array: "<<endl;
    cin>>n;
    // declared an extra array named arr1 for executing out-place algo
    int arr[n],arr1[n];
    cout<<"enter the elements of array separated by space: "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"array after sorting using in-place algo"<<endl;
    insertion_sort_IP(arr,n);
    print(arr,n);
    cout<<endl;

    // this step has been done to copy the elements of arr into arr1 so that it doesnt take garbage values;
    for(int i=0;i<n;i++) arr1[i]=arr[i];

    cout<<"array after sorting using out-place algo"<<endl;
    // in the function i have passed arr which is actual input array, arr1 is the extra array which we have declared to store our answer    
    insertion_sort_OP(arr,arr1,n);
    print(arr1,n);
    cout<<endl;
}

Ques3=Practical examples of using in-place and out-place techniques.
Ans:
#IN - PLACE
1.For exapmle if we want to reverse an array then its in-place algorithm will be swaping the first and last element of array until we reach the  middle of array,
2.In many cases, the space requirements of an algorithm can be drastically cut by using a in place algorithm.
3. For example, say we wish to know if two vertices in a graph of n vertices are in the same connected component of the graph. There is no known simple, deterministic,
in-place algorithm to determine this, but if we simply start at one vertex and perform a random walk of about 20n3 steps, the chance that we will stumble across the 
other vertex provided that it is in the same component is very high
4. Similarly, there are simple randomized in-place algorithms for primality testing such as the Miller–Rabin primality test
5.there are also simple in-place randomized factoring algorithms such as Pollards rho algorithm.

#OUT-PLACE 
1.If we want to solve the same problem using out-place algorithm we have to create one extra array of same size and copy elements of original array from back to the 
front of new array,this algorith increases the space complexity to O(n) as we have creaed an extra array.
2.merge sort is an example of out of place.
3.Now a days, using out-of-place sorting is a much better option because most of the computers offers decent amount of RAM. So even if this method of sorting uses
extra memory, the program can still get executed.
then out of place algorithm can be used in editing the spreadsheet,browsing internet and performing day to day life easy tasks.
