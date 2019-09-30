from collections import Counter

N = int(input())
A = list(map(int, input().split()))

C = Counter(A)

ans = 0
for i, v in C.items():
    if v > i:
        ans += v-i
    elif v < i:
        ans += v

print(ans)