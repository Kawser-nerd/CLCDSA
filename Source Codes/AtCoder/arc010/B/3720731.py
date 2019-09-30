N = int(input())
s = [0,0,31,60,91,121,152,182,213,244,274,305,335]
d = [0 for i in range(366)]
for i in range(366):
    if i % 7 == 0 or i % 7 == 6:
        d[i] = 1
for i in range(N):
    md = list(map(int, input().split("/")))
    dd = s[md[0]] + md[1]
    while d[dd-1] == 1:
        dd += 1
        if dd == 367:
            dd = 366
            break
    d[dd-1] = 1
    
ans = 0
ansb = 0
for i in range(366):
    
    if d[i] == 1:
        ansb += 1
    else:
        ansb = 0
    ans = max(ans, ansb)
print(ans)