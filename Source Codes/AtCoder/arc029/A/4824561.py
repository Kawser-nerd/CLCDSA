# -*- coding: utf-8 -*-

N = int(input())
t = [0] * N
for i in range(N):
    t[i] = int(input())

ans = 100000000000

#bit???
n = N
arr = [0] * n
for i in range(2 ** n):
    for j in range(n):
        if((1&i>>j) == 1):
            arr[j] = 1
        else:
            arr[j] = 0
    #?????
    a_time = 0
    b_time = 0
    time = 0
    for j in range(len(arr)):
        if arr[j] == 0:
            a_time += t[j]
        else:
            b_time += t[j]
    time = max(a_time,b_time)
    ans = min(ans,time)

print(ans)