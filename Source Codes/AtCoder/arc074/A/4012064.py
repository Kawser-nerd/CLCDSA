H,W = map(int,input().split())

if H%3 == 0 or W%3 == 0:
    print(0)
    exit()

ans = min(H,W)

for i in range(1,W):
    a = i*H
    if H%2:
        b = (W-i)*(H//2)
        c = (W-i)*(H//2+1)
        tmp = max(a,b,c) - min(a,b,c)
    else:
        b = (W-i)*(H//2)
        tmp = max(a,b) - min(a,b)
    ans = min(ans, tmp)

H,W = W,H

for i in range(1,W):
    a = i*H
    if H%2:
        b = (W-i)*(H//2)
        c = (W-i)*(H//2+1)
        tmp = max(a,b,c) - min(a,b,c)
    else:
        b = (W-i)*(H//2)
        tmp = max(a,b) - min(a,b)
    ans = min(ans, tmp)

print(ans)