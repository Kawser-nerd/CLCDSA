n, m   = map(int, input().split())
has    = [False for _ in range(n)]
has[0] = True  
count  = [1     for _ in range(n)]

for _ in range(m):
    x, y = map(int, input().split())
    x -= 1; y-= 1
    
    count[x] -= 1
    count[y] += 1
    
    if has[x] == True:
        has[y] = True
        if count[x] == 0:
            has[x] = False
ans = 0
for x in has:
    if x == True: ans += 1
print(ans)