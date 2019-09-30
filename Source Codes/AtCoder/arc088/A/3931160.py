X,Y = map(int,input().split())
ans = 1
while True :
    X *= 2
    if X > Y :
        break
    ans += 1
print(ans)