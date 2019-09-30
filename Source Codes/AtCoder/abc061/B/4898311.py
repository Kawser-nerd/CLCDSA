n,m = map(int,input().split())
cnt = [ 0 for i in range(n) ]
for i in range(m):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    cnt[a] += 1
    cnt[b] += 1
for i in cnt:
    print(i)