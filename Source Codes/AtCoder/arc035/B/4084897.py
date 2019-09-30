n = int(input())
t = [0]*n
for i in range(n):
    t[i]=int(input())
t.sort()

m = 10**9+7
res = 0
ass = 1

p = [1]
for i in range(1,n+1):
    p.append(p[-1]*i%m)

c = 0
k = 1

for i in range(n):
    c += t[i]
    res += c
    
    if i != n-1:
        if t[i] != t[i+1]:
            ass = ass*p[k]%m
            k = 1
        else:
            k += 1
    else:
        ass = ass*p[k]%m
print(res)
print(ass)