N, M = map(int, input().split())
nums = []
for i in range(M):
    j,k = map(int, input().split())
    nums.append(j)
    nums.append(k)
for i in range(N):
    print(nums.count(i+1))