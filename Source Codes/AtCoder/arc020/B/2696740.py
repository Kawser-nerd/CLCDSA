from itertools import permutations

N, C = map(int, input().split())
A = [int(input()) for i in range(N)]

ans = float('inf')
for a, b in permutations(range(1, 11), r=2):
    tmp = 0
    for i in range(N):
        if i % 2 == 0 and A[i] != a:
            tmp += C
        if i % 2 == 1 and A[i] != b:
            tmp += C

    ans = min(ans, tmp)

print(ans)