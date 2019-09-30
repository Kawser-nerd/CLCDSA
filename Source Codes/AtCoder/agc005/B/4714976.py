n = int(input())
a = list(map(int, input().split()))

l = []
r = []
s = []

for i, x in enumerate(a):
    left = i
    while len(s) > 0  and x < s[-1][0]:
        left = s[-1][1]
        s.pop()
        
    l.append(left)    
    s.append([x, left])

s = []
for i in range(n-1, -1, -1):
    right = i
    x = a[i]
    while len(s) > 0  and x < s[-1][0]:
        right = s[-1][1]
        s.pop()
        
    r.append(right)    
    s.append([x, right])
r = r[::-1]

ans = 0    
for i, (x, left, right)  in enumerate(zip(a,l,r)):
    ans += x * (right+1-i) * (i+1-left)
print(ans)