#ifndef MIN_HEAP_H
#define MIN_HEAP_H

using namespace std;       

class MinHeap
{
  private:

    int *arr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap

  public:

    // Constructor for the MinHeap
    MinHeap(int cap) {
        heap_size = 0; 
        capacity = cap; 
        arr = new int[cap]; 
    }

    void swap(int *x, int *y)
{
int temp = *x;
*x = *y;
*y = temp;
}
    // to ge the index of parent of node at index i
    inline int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    inline int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    inline int right(int i) { return (2*i + 2); } 

    // Returns the minimum key (key at root) from min heap 
    inline int getMin() {  return arr[0]; } 

    // Inserts a new key 'k' 
    void insertKey(int k) {
    
        if (heap_size == capacity)
        {
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        arr[i] = k;

        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
    }
    void Heapify(int i){
        int l = left(i);
        int r = right(i);
        int min = i;
        if (l < heap_size && arr[l] < arr[i])
            min = l;
        if (r < heap_size && arr[r] < arr[min])
            min = r;
        if (min != i)
        {
            swap(&arr[i], &arr[min]);
            Heapify(min);
        }
}
    // Extract the root which is the minimum element 
    int extractMin() {
    if (heap_size <= 0)
        return 0;
    if (heap_size == 1)
    {
        heap_size--;
        return arr[0];
    }
 

    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    Heapify(0);
    return root;
}
  
    // Decreases key value of key at index i to newVal 
    void decreaseKey(int i, int newVal) {
    arr[i] = newVal;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
       swap(&arr[i], &arr[parent(i)]);
       i = parent(i);
    }
}
  
    // Deletes a key stored at index i 
    void deleteKey(int i) {
    decreaseKey(i, 0);
    extractMin();
}
};

#endif
