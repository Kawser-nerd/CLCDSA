from itertools import permutations
a = list(map(int, input().split()))
ans = []
for x in permutations([0, 0, 1, 1, 1]):
    sum = 0
    for i, y in enumerate(x):
        if y == 1:
            sum += a[i]
    ans.append(sum)
b = list(set(ans))
b.sort()
print(b[-3])