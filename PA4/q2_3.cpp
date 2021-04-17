#include<iostream>
#include<climits>
#include"MinHeap.h"
using namespace std;

int kthSmallest(int arr[], int n, int k) { 
    // Build a heap of n elements: O(n) time 
    MinHeap min(arr, n); 
  
    // Do extract min (k-1) times 
    for (int i = 0; i < k - 1; i++) 
        min.extractMin(); 
  
    // Return root 
    return min.getMin(); 
}

int main(){
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    int* arr = new int[n];
    cout << "Enter n integers space separated: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Kth Smallest Integer: " << kthSmallest(arr, n, k) << endl;
    return 0;
}
