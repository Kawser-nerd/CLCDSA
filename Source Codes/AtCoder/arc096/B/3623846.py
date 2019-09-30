n,c = map(int,input().split())
lis = [list(map(int,input().split())) for i in range(n)]
ans = 0
num = 0
nu = 0
cou = 0
co = 0
go = 0
left = []
right = []
for i in range(n):
    num += lis[i][1]
    go = lis[i][0]
    ans = max(ans,num-go)
    if cou < num-go:
        cou = num-go
        left.append([go,num])
    else:
        try:left.append(left[-1])
        except:left.append([0,0])

for i in reversed(range(n)):
    nu += lis[i][1]
    go = c-lis[i][0]
    ans = max(ans,nu-go)
    if co < nu-go:
        co = nu-go
        right.append([go,nu])
    else:
        try:right.append(right[-1])
        except:right.append([0,0])
gone = 0
gon = 0
for i in range(n-1):
    gone += lis[i][1]
    ans = max(ans,gone + right[n-i-2][1] - lis[i][0] * 2 - right[n-i-2][0])
    gon += lis[-(i+1)][1]
    ans = max(ans,gon + left[n-i-2][1] - (c-lis[-(i+1)][0]) * 2 - left[n-i-2][0])
print(ans)