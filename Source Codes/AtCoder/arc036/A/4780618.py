# -*- coding: utf-8 -*-

n, k = map(int, input().split())
sleeptime = []

for _ in range(n):
    time = int(input())
    sleeptime.append(time)

ans = -1
    
for i in range(n-2):
    if sleeptime[i] + sleeptime[i+1] + sleeptime[i+2] < k:
        ans = i + 3
        break

print(ans)