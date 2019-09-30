import bisect
n =int(input())
d=[int(input()) for i in range(n)]
d.sort()
m = 10**9+7

#third[i]:????d[i]??????????
third = [0]*n
for i in range(n):
    third[i] = n-bisect.bisect_left(d,d[i]*2)

#sthird[i]:third[i]~third[n-1]????
sthird = [0]*(n+1)
for i in range(n-1,-1,-1):
    sthird[i] = (sthird[i+1]+third[i])%m

#second
second = [0]*n
for i in range(n):
    k = n-third[i]
    second[i] = sthird[k]

#Ssecond
Ssecond = [0]*(n+1)
for i in range(n-1,-1,-1):
    Ssecond[i] = (Ssecond[i+1]+second[i])%m

#first
first = [0]*n
for i in range(n):
    k = n - third[i]
    first[i] = Ssecond[k]

#res
res = 0
for i in range(n):
    res = (res + first[i])%m

print(res)