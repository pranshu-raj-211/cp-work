import numpy as np


def input_arr():
    arr = list()
    n = int(input("Enter number of elements in array "))
    print("Enter elements ")
    for i in range(n):
        x = int(input())
        arr.append(x)


def driver(arr, n):
    output = count_sort(arr, n)
    print("The sorted array is :", output, sep="\n")


def count_sort(arr, n):
    minimum = min(arr)  # can be used to normalize values when not in range 0-9
    counts = [0 for _ in range(n)]
    output = [0 for _ in range(n)]

    # getting initial counts
    for i in range(n):
        counts[arr[i]] += 1

    # lambda function to get cumulative sum of counts as an array
    counts = np.cumsum(counts)

    for i in range(n):
        output[counts[arr[i]] - 1] = arr[i]
        counts[arr[i]] -= 1

    # output = [x + minimum for x in output]
    # next, add something to normalize that array

    return output


driver([0, 1, 3, 0, 2, 4, 6, 3, 2, 0, 9, 4, 2], 13)
