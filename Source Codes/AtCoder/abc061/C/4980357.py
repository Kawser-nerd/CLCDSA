N,K = map(int,input().split())

nums = []
for i in range(0,N):
    ab = list(map(int,input().split()))
    nums.append(ab)

nums = sorted(nums,key = lambda x: x[0])
tmp = 0
index = 0
for i in range(0,N):
    tmp += nums[i][1]
    if tmp >= K:
        index = i
        break

print(nums[i][0])