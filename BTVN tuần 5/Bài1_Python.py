def sort_colours(nums):
    pivot=1
#First Sort : Move element(0)<pivot to the LEFT
    smaller=0
    for i in range(0,len(nums)):
        if nums[i]<pivot:
            nums[smaller], nums[i] = nums[i], nums[smaller]
            smaller+=1
#Second Sort : Move element(2)>pivot to the RIGHT
    larger=len(nums)-1
    for i in reversed(range(0,len(nums))):
        if nums[i]>pivot:
            nums[larger], nums[i] = nums[i], nums[larger]
            larger-=1
        elif nums[i]<pivot:
            break
    return nums

#Test với đầu vào ngẫu nhiên
nums=[1,2,1,2,0,0,0,1,2,1,0,2,0,1,0,2,1,0,1,2,2,2,2,1,1,0,0]
sorted_arr=sort_colours(nums)

#In ra kết quả
print("Mảng đã sắp xếp:", sorted_arr)