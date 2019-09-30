from collections import defaultdict
import sys

N = int(input())
A = map(int, input().split())

counts = defaultdict(int)
mod = N % 2

for a in A:
    if a % 2 == mod:
        print(0)
        sys.exit()
    counts[a] += 1
    if a == 0 and counts[a] > 1:
        print(0)
        sys.exit()
    if a > 0 and counts[a] > 2:
        print(0)
        sys.exit()

total = 2**(N // 2)
print(total % (10**9+7))