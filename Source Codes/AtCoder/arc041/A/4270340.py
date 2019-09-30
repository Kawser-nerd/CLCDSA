x,y = map(int,input().split(" "))
k = int(input())
ans = 0

if k <= y:
    ans = x + k
else:
    ans = y + (x - k + y)

print(ans)