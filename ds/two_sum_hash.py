def check_for_sum(arr, sumc):
    map = {}
    for key, i in enumerate(arr):
        map[key] = 0
    for key in map.keys():
        complement = sumc - key
        if complement in map.keys():
            return True
    return False


def main():
    n = int(input("Enter size of list"))
    arr = list()
    for i in range(n):
        x = int(input("enter element "))
        arr.append(x)

    sumc = int(input("enter sum to check for "))
    exists = check_for_sum(arr, sumc)
    if exists:
        print("true")
    else:
        print("false")


if __name__ == "__main__":
    main()
