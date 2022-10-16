// Name = Dheeraj Batra ; sid=21104030 ; branch=EE

// we can search element in array using linear or binary search
// for that we need the array itself and the target
// in this question since we dont know the size of array so it will be difficult to give the instruction to the loop that where it will stop

// method-1
// we can find size of array using inbulit function i.e
// int arr[]={1,2,3,4,6,7,8,9,2,10,11};
// int size=sizeof(arr)/sizeof(arr[0]);
// now since we have got the size of array we can specify the range for iteration in while loop 

// method-2
// in this method we will initialise high variable by 1 and till the time element will not be found we will twice its value 
// for better understanding i have given the code below;
#include <bits/stdc++.h>
using namespace std;

// pre requisite for binary search is it should be sorted 
int binary_searching(vector<int> &arr, int l, int r, int x){
    // l is low ; r is high ; x is element to be searched
    while(l <= r){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_searching(arr, l, mid - 1, x);
        return binary_searching(arr, mid + 1, r, x);
    }
    return -1;
}

int findpos(vector<int> &arr, int key){
    int l = 0;
    int h = 1;
    int val = arr[0];

    // this while loop is used to set the range for binary function
    while (val < key){
        l = h;   // store previous high
        h = 2 * h;  // double the range of search
        val = arr[h];  // update new value
    }
    // after the while  loop is over we call binary function on updated values of l and h
    return binary_searching(arr, l, h, key);
}

int main(){
    // n is the number of elements in an array
    int n;
    cin >> n;

    // v is the vector used to store elements,enter the elements of array separated by space
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // target is the int variable used to store the element to be searched in an array
    int target;
    cin >> target;

    int ans = findpos(v, target);
    if (ans == -1)
        cout << "element not found";
    else
        cout << "element found at index " << ans << endl;
}
