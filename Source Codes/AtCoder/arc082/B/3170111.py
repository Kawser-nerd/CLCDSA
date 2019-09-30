import math
n = int(input())
p = list(map(int, input().split()))
ans = 0
tmp = 0
for i in range(1, n+1):
    if p[i-1] == i:
        tmp += 1
    elif tmp > 1:
        ans += math.ceil(tmp/2)
        tmp = 0
    elif tmp == 1:
        ans += tmp
        tmp = 0

if tmp > 1:
    ans += math.ceil(tmp / 2)
    tmp = 0
elif tmp == 1:
    ans += tmp
    tmp = 0
print(ans)