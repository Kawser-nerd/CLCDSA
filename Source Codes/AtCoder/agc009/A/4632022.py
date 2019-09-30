n = int(input())
a = []
b = []
for i in range(n):
    x,y = map(int,input().split())
    a.append(x)
    b.append(y)
a = a[::-1]
b = b[::-1]

cnt = 0
for i in range(n):
    ac = a[i]+cnt
    if ac % b[i] != 0:
        cnt += b[i]*(ac//b[i]+1) - ac    
print(cnt)