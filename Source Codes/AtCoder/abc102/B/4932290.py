N = int(input())
A = list(map(int, input().split()))
ans = 0

from itertools import combinations

for i, j in combinations(A, 2):
    ans = max(ans, abs(i - j))

print(ans)