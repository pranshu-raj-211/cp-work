#include <iostream>

using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    // making two subarrays out of the bigger array
    int *first = new int(len1);
    int *second = new int(len2);

    // copying values
    int main_array_index = start;

    for (int i = 0; i < len1; i++)
        first[i] = arr[main_array_index++];

    main_array_index = mid + 1;

    for (int i = 0; i < len2; i++)
        second[i] = arr[main_array_index++];

    // merge the two sorted subarrays
    int index1 = 0;
    int index2 = 0;
    main_array_index = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
            arr[main_array_index++] = first[index1++];
        else
            arr[main_array_index++] = second[index2++];
    }

    while (index1 < len1)
        arr[main_array_index++] = first[index1++];

    while (index2 < len2)
        arr[main_array_index++] = second[index2++];
}

void merge_sort(int *arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    // solve left subarray recursively
    merge_sort(arr, start, mid);

    // solve right subarray recursively
    merge_sort(arr, mid + 1, end);

    // merge the resulting arrays
    merge(arr, start, end);
}

int main()
{
    int x, n;

    cout << "Enter length of array : ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
    }

    merge_sort(arr, 0, n);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << ", ";
    }
}