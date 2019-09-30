n,a,b,c,d = map(int,input().split())

res = 0
r = b-a
for k in range(1,n):
    s1 = k*c - d *(n-1-k)
    t1 = k*c - c *(n-1-k)
    if s1 <= r and r <= t1:
        res = 1
        break
    
    s1 = k*d - d *(n-1-k)
    t1 = k*d - c *(n-1-k)
    if s1 <= r and r <= t1:
        res = 1
        break

if res == 1:
    print("YES")
else:
    print("NO")