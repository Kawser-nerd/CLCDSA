import sys
n, a, b = map(int, input().split())
s = [int(input()) for i in range(n)]

dif = max(s)-min(s)
if dif == 0:
    print(-1)
    sys.exit()

p = b/dif
q = a - sum(s)*p/n
print(p, q)