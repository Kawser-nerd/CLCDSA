from collections import Counter

H, W, N = map(int, input().split())

# dict[(i, j)]: ???(i,j)???3*3???????????????
dict = {}
for  _ in range(N):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    for i in range(max(0, a - 2), min(H - 3, a) + 1):
        for j in range(max(0, b - 2), min(W - 3, b) + 1):
            dict[(i, j)] = dict.get((i, j), 0) + 1

nums = Counter(dict.values())
print((H - 2) * (W - 2) - sum(nums.values()))
for i in range(1, 10):
    if i in nums:
        print(nums[i])
    else:
        print(0)