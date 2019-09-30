import sys
N = int(input()) 
A = [int(sys.stdin.readline()) for _ in range(N)]
b = 0
for i, a in enumerate(A):
    if i + b < a:
        print(-1)
        sys.exit()
    else:
        b = a - i
ans = 0
pre = -1
for a in A[::-1]:
    if pre - 1 != a:
        ans += a
    pre = a
print(ans)