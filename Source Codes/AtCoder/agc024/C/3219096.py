n = int(input())
x = [int(input()) for _ in range(n)]
f = 0

if x[0]>0: f = 1
for i in range(n-1):
    if x[i]+1 < x[i+1]: f = 1
import sys
if f:
    print(-1)
    sys.exit()
ans = 0
for i in range(n-1):
    if x[i+1] == x[i]+1:
        ans += 1
    else:
        ans += x[i+1]
print(ans)