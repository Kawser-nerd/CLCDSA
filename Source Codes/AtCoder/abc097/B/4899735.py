#coding: utf-8
X = int(input())
ans = 0
for b in range(1, 32):
    for p in range(2, 10):
        if b**p <=X:
            ans = max(ans, b**p)
print(ans)