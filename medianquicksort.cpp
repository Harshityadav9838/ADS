#include <iostream>
using namespace std;

int medianOfThree(int arr[], int low, int high)
{
    int mid = (low + high) / 2;

    if ((arr[low] > arr[mid]) != (arr[low] > arr[high]))
        return low;
    else if ((arr[mid] > arr[low]) != (arr[mid] > arr[high]))
        return mid;
    else
        return high;
}

int partition(int arr[], int low, int high)
{
    int medianIndex = medianOfThree(arr, low, high);

    // Put median pivot at the end
    swap(arr[medianIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {8, 3, 7, 2, 9, 5, 4};
    int n = 7;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}