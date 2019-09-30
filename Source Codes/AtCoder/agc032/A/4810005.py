n = int(input())
nums = list(map(int,input().split()))

operation = []
for i in range(n):
    for j in range(len(nums)):
        if nums[len(nums)-j-1] == len(nums)-j:
            operation.append(nums[len(nums)-j-1])
            del nums[-j-1]
            break

if len(nums) == 0:
    for elem in reversed(operation):
        print(elem)
else:
    print(-1)