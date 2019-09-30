import math

K = int(input())
A = list(map(int,input().split()))[::-1]

mi = 2
ma = 2
res = 0

for i in range(K) :
    if (mi % A[i]) and (ma % A[i]) and ((mi // A[i]) == (ma // A[i])) :
        res = -1
        break
    
    mi = math.ceil(mi / A[i]) * A[i]
    ma = math.floor(ma / A[i]) * A[i] + A[i] - 1

if res == -1 :
    print(res)
else :
    print(mi,ma)