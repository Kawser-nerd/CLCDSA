n,m = map(int,input().split())
ch = [[0]*n for i in range(n)]
for _ in range(m):
    x,y = map(int,input().split())
    ch[x-1][y-1] = 1
ans = 1
for i in range(2 ** n):
    s = format(i,"b").zfill(n)
    key = 1
    for j in range(n-1):
        for k in range(j+1,n):
            if s[j] == "1" and s[k] == "1" and ch[j][k] == 0:
                key = 0
    if key:
        ans = max(ans,s.count("1"))
print(ans)