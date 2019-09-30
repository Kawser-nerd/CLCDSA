from itertools import permutations

n, c = map(int, input().split())
inputs = [int(input()) for _ in range(n)]
ans = 10 ** 10
for item in permutations(range(1, 11), 2):
    count = 0
    first, second = item[0], item[1]
    for i in range(n):
        if i % 2 == 0 and inputs[i] != first:
            count += c
        elif i % 2 == 1 and inputs[i] != second:
            count += c
    ans = min(ans, count)

print(ans)