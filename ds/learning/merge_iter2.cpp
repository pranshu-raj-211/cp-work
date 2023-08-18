#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // copying values
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;

    // merging the subarrays
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr)
{
    int n = arr.size();
    int currSize;

    // create subarrays of different sizes
    for (currSize = 1; currSize <= n - 1; currSize = 2 * currSize)
    {
        // iterate over the array in steps of 2*currSize(to call merge on all subarrays)
        for (int start = 0; start < n - 1; start += 2 * currSize)
        {
            int mid = start + currSize - 1;
            int end = min(start + 2 * currSize - 1, n - 1);
            merge(arr, start, mid, end);
        }
    }
}

int main()
{
    int n, x;
    cout << "Enter length of array : ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
    }

    mergeSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
