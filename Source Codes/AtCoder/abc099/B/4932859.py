a,b = map(int,input().split())
n = b-a
tmp = n*(n+1)//2
ans = tmp - b
print(ans)