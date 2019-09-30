X,Y = map(int,input().split())
ans = 0
while X <= Y:
    X *= 2
    ans += 1
print(ans)