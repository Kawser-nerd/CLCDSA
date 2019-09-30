from itertools import combinations

N = int(input())
inputs = [list(map(int, input().split())) for _ in range(N)]

count = 0
for item in combinations(inputs, 3):
    A, B, C = item[0], item[1], item[2]
    if A[0] == B[0] == C[0]:
        continue
    elif A[1] == B[1] == C[1]:
        continue
    S = abs((B[0] - A[0]) * (C[1] - A[1]) - (B[1] - A[1]) * (C[0] - A[0]))
    if S != 0 and S % 2 == 0:
        count += 1

print(count)