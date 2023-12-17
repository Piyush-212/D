#include <iostream>
using namespace std;

void heap(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heap(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
       swap(a[0], a[i]);
        heap(a, i, 0);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
   cout <<endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

   cout << "Before sorting array elements are - \n";
    printArr(a, n);

    heapSort(a, n);

    cout << "After sorting array elements are - \n";
    printArr(a, n);

    return 0;
}