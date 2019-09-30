nums = sorted(list(map(int, input().split())))
n = nums[0] * nums[1]
if nums[2] % 2:
    print(n)
else:
    print(0)