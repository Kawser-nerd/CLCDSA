n = int(input())
k = 1000000
nums = [0 for _ in range(k+2)]
for _ in range(n):
  a, b = map(int,input().split())
  nums[a]+=1
  nums[b+1]-=1

for i in range(1,k+1):
  nums[i]+=nums[i-1]
print(max(nums))