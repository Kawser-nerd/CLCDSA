n,m = map(int,input().split())
lis = list(map(int,input().split()))
li = [0 for i in range(n)]
for i in range(n):li[lis[i]-1] += 1
li.sort(reverse = True)
ans = 0
for k in range(m):
    ans += li[k]
print(n-ans)