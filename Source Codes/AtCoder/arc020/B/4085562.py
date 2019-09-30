from itertools import permutations

n, c = map(int, input().split())
inputs = [int(input()) for _ in range(n)]

ans = 0
for first, second in permutations(range(1, 11), 2):
    count = 0
    for i in range(n):
        if (i % 2 == 0 and inputs[i] == first) or (i % 2 == 1 and inputs[i] == second):
            count += 1
    ans = max(ans, count)

print(c * (n - ans))