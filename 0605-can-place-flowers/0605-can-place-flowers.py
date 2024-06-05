class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        place = 0
        if len(flowerbed)<=2:
            if flowerbed[0]==0 and flowerbed[-1]==0:
                place=1
            
        else:
            if flowerbed[0]==0 and flowerbed[1]==0:
                place=1
                flowerbed[0]=1


            for i in range(1,len(flowerbed)-1):
                if flowerbed[i]==1:
                    continue
                if flowerbed[i]==0 and flowerbed[i-1]==0 and flowerbed[i+1]==0:
                    place+=1
                    flowerbed[i]=1

            if flowerbed[-1]==0 and flowerbed[-2] == 0:
                place+=1
    
        if place>=n:
            return True
        
        return False