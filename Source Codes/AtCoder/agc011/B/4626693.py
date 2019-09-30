n = int(input())
a = list(map(int,input().split()))
a.sort()

b = []
c = 0
for i in range(n):
    c += a[i]
    b.append(c)
a.sort(reverse=True)
b.sort(reverse=True)

d = 0
for i in range(1,n):
    if b[i]*2 < a[i-1]:
        d = i
        break
        
if d:
    print(d)
else:
    print(n)