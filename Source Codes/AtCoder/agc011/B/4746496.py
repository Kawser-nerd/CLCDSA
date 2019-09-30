n = int(input())
a = list(map(int, input().split()))

a.sort()
s = [0 for _ in range(n)]
s[0] = a[0]

for i in range(1, n):
    s[i]  = s[i-1] + a[i]
    
for i in range(n):
    s[i] *= 2

def find(a, x):
    u, l = len(a), -1
    
    while u > l+1:
        md = (u+l) // 2
        if x >= a[md]:
            l = md
        else:
            u = md
    return u - 1      

ans = [0 for _ in range(n)]
for i in range(n):
    cur = i 
    nx  = find(a, s[i])
    while nx != cur:
        cur = nx
        nx  = find(a, s[nx])
    ans[i] = nx
    
count = 0    
for x in ans:
    if x == len(a) - 1:count+=1
print(count)