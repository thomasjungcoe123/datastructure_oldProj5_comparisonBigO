
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;
int* A;
int* B;
int X[] = { 1000, 2000, 3000, 4000, 5000};

/*quick sort takes in an array and then sorts it must know left and right */
void quicksort(int* list, int left, int right, int size)
{
    if (left < right)
    {	// Pivot Value Choice Step
        int pivot = list[left]; // Partition Step
        int i = left;
        int j = right + 1;
        do
        {
            do
            {
                j = j - 1;
            } while (list[j] > pivot);
            if (i < j)
                swap(list[i], list[j]);
        } while (i < j);
        swap(list[left], list[j]); // Recursive Step
        quicksort(list, left, j - 1, size);
        quicksort(list, j + 1, right, size);
    }
}
/*selection sort takes in an array and then sorts it */
void selectionSort(int* list, int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int maxIndex = 0; // largest element in subarray
        for (int j = 0; j <= i; j++)
        {
            if (list[j] > list[maxIndex])
                maxIndex = j;
        }
        swap(list[i], list[maxIndex]); // place largest element in its proper place
    }
}
/*insertion sort taken in array and sorted */
void insertionSort(int* list, int size)
{
    int i;
    int j;
    int insertElement;
    for (i = 1; i < size; i++)
    {
        insertElement = list[i];
        j = i - 1;
        while ((j >= 0) && (insertElement < list[j]))
        {

            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = insertElement;
    }
}

/* heapify is a helper method used for heapsort */
void heapify(int* list, int size, int root)
{	// To heapify a subtree rooted with node root which is
    // an index in arr[]. size is size of heap
    int largest = root;  // Initialize largest as root
    int l = 2 * root + 1;  // left = 2*root + 1
    int r = 2 * root + 2;  // right = 2*root + 2
    if (l < size && list[l] > list[largest]) // If left child is larger than root
        largest = l;
    if (r < size && list[r] > list[largest]) // If right child is larger than largest so far
        largest = r;
    if (largest != root) // If largest is not root
    {
        swap(list[root], list[largest]); // Recursively heapify the affected sub-tree
        heapify(list, size, largest);
    }
}

/* heapsort takes in the array builds a heap and sorts accordingly */
void heapSort(int* list, int size)
{// main function to do heap sort
    for (int i = size / 2 - 1; i >= 0; i--) // Build heap (rearrange array)
        heapify(list, size, i);
    for (int i = size - 1; i >= 0; i--) // One by one extract an element from heap
    {
        swap(list[0], list[i]); // Move current root to end
        heapify(list, i, 0); 	// call max heapify on the reduced heap
    }
}
void randomize(int* A, int size)
{
    for (int i = 0; i < size; i++)
    {
        A[i] = rand();
    }
}
void filler(int* A, int* B,int size)
{
    for (int i = 0; i < size; i++)
    {//Fill up the array A with random numbers
        //Make a copy of A into B.
        B[i] = A[i];
    }
}
void display(int* A, int size)
{
    int i = 0;
    //Call your first sorting method on B
    while (i != size)
    {
        cout << A[i] << " ";
        i++;
    }
}
//In order to evaluate the number of ticks(on windows) you may use a routine similar to the one below.
int main(void)
{
    //create random number from time and srand();
    LARGE_INTEGER start, stop;
    srand(time(NULL)); 	//Create a seed
    int size = 30;
    A = new int[size];
    B = new int[size];

    cout << "randomize" << endl;
    randomize(A, size);
    //display(A, size);
    //cout << endl;

    cout << "filled" << endl;
    filler(A, B, size); //Make a copy of A into B.
    //display(B, size);
    //cout << endl;

    cout << "quicksort" << endl;
    quicksort(B, 0, 29, 30);//call first sorting method
    //display(B, size); //Print the sorted array B.
    //cout << endl;

    cout << "filled" << endl;
    filler(A, B, size); //Make a copy of A into B.
    //display(B, size);
    //cout << endl;

    cout << "selectionSort" << endl;
    selectionSort(B, size);//Call your second sorting method on B.
    //display(B, size); //Print the sorted Array B.
    //cout << endl;

    cout << "filled" << endl;
    filler(A, B, size); //Make a copy of A into B.
    //display(B, size);
    //cout << endl;

    cout << "insertionSort" << endl;
    insertionSort(B, size);//Call your second sorting method on B.
    //display(B, size); //Print the sorted Array B.
    //cout << endl;

    cout << "filled" << endl;
    filler(A, B, size); //Make a copy of A into B.
    //display(B, size);
    //cout << endl;

    cout << "heapSort" << endl;
    heapSort(B, size);//Call your second sorting method on B.
    //display(B, size); //Print the sorted Array B.
    //cout << endl;

    delete[] A;
    for (int k = 0; k < 5; k++)
    {
        A = new int[X[k]];
        B = new int[X[k]];
        size = X[k];
        int qs = 0;
        int ss = 0;
        int is = 0;
        int hs = 0;
        for (int q = 0; q < 10; q++)
        {
            randomize(A, size); //fill up A with x[k] random numbers

            filler(A, B, size); //copy contents of A into B.
            QueryPerformanceCounter(&start); //start the tick counter
            quicksort(B, 0, 29, 30); //perform sorting 1
            QueryPerformanceCounter(&stop); //end the tick counter
            //cout << " startTime: "<< start.QuadPart << " stopTime: "<<stop.QuadPart << " difference: "<< stop.QuadPart - start.QuadPart << endl; //print values
            qs = qs+stop.QuadPart - start.QuadPart;

            filler(A, B, size); //copy contents of A into B.
            QueryPerformanceCounter(&start); //start the tick counter
            selectionSort(B,size); //perform sorting 2
            QueryPerformanceCounter(&stop); //end the tick counter
            //cout << " startTime: " << start.QuadPart << " stopTime: " << stop.QuadPart << " difference: " << stop.QuadPart - start.QuadPart << endl; //print values
            ss = ss+stop.QuadPart - start.QuadPart;

            filler(A, B, size); //copy contents of A into B.
            QueryPerformanceCounter(&start); //start the tick counter
            insertionSort(B, size); //perform sorting 3
            QueryPerformanceCounter(&stop); //end the tick counter
            //cout << " startTime: " << start.QuadPart << " stopTime: " << stop.QuadPart << " difference: " << stop.QuadPart - start.QuadPart << endl; //print values
            is = is+stop.QuadPart - start.QuadPart;

            filler(A, B, size); //copy contents of A into B.
            QueryPerformanceCounter(&start); //start the tick counter
            heapSort(B, size); //perform sorting 4
            QueryPerformanceCounter(&stop); //end the tick counter
            //cout << " startTime: " << start.QuadPart << " stopTime: " << stop.QuadPart << " difference: " << stop.QuadPart - start.QuadPart << endl; //print values
            hs = hs+stop.QuadPart - start.QuadPart;
            //Housekeeping to calculate the average

        }
        //find the average
        qs = qs / 10;
        ss = ss / 10;
        is = is / 10;
        hs = hs / 10;

        cout << "averages(qs, ss, is hs): " << qs << " " << ss << " " << is << " " << hs << " " << endl;

        delete[] A;
        delete[] B;
    }
    return 0;
}
