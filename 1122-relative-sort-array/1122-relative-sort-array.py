class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr_set = set(arr2)
        outer = []
        count = [0]*len(arr2)
        for i in arr1:
            if i in arr_set:
                count[arr2.index(i)]+=1
            else:
                outer.append(i)
        
        arr = []
        for i in range(len(arr2)):
            arr.extend([arr2[i]]*count[i])
        arr.extend(sorted(outer))
        return arr
            
            