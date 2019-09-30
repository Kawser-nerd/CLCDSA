nums = [int(input()) for i in range(3)]
for num in nums:
    print(sorted(nums,reverse=True).index(num)+1)