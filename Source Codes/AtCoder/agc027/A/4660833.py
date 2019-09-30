#coding: utf-8
N, x = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
a.sort()
for i in range(len(a)):
    x -= a[i]
    ans += 1
    if x < 0:
        ans -= 1
print(ans if x <= 0 else ans - 1)