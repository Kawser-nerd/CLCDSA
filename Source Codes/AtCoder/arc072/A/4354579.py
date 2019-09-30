N = int(input())
A = list(map(int,input().split()))

calc1 = 0
calc2 = 0

L = A

if L[0] > 0 :
    su = L[0]
else :
    su = 1
    calc1 += 1 + abs(L[0])

for i in range(1,N) :
    su += L[i]
    if i % 2 :
        if su >= 0 :
            calc1 += 1 + abs(su)
            su = -1
    else :
        if su <= 0 :
            calc1 += 1 + abs(su)
            su = 1

L = A

if L[0] < 0 :
    su = L[0]
else :
    su = -1
    calc2 += 1 + abs(L[0])

for i in range(1,N) :
    su += L[i]
    if not i % 2 :
        if su >= 0 :
            calc2 += 1 + abs(su)
            su = -1
    else :
        if su <= 0 :
            calc2 += 1 + abs(su)
            su = 1
print(min(calc1,calc2))