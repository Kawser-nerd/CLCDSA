a,b,k = map(int,input().split())
ans = set()
for i in range(min(b-a+1,k)):
    ans.add(a+i)
for i in range(min(b-a+1,k)):
    ans.add(b-i)

ans = sorted(ans)
for i in ans:
    print(i)