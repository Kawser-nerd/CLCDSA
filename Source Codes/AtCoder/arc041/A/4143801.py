x,y = map(int,input().split())
k = int(input())

if y >= k :
    ans = x+k
else :
    k -= y
    x -= k
    ans = x+y

print(ans)