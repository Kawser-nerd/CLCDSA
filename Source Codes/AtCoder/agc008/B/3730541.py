n,k = map(int,input().split())
a = list(map(int,input().split()))

b = [0] #a[i]???sum
c = [0] #a[i]???+???sum

for i in range(n):
    b.append(b[-1]+a[i])
    if a[i] > 0:
        c.append(c[-1]+a[i])
    else:
        c.append(c[-1])


res = 0
for i in range(n-k+1):
    if b[i+k]-b[i] > 0:
        w = b[i+k]-b[i] + (c[i]-c[0]) + (c[n]-c[i+k])
    else:
        w = c[i]-c[0]+c[n]-c[i+k]
    res = max(res,w)
print(res)