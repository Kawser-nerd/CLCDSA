import copy

n = int(input())

nums = []
for i in range(n):
    nums.append(int(input()))

taiou = {}
reprica = copy.copy(nums)
reprica.sort()
for i, r in enumerate(reprica):
    taiou[r] = i
ans = 0
for i, num in enumerate(nums):
    if i % 2 != taiou[num] % 2:
        ans += 1

print(ans // 2)