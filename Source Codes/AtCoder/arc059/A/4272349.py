N = int(input())
n = list(map(int,input().split()))
costlist = []
for i in range(min(n)-1,max(n)+1):
    cost = 0
    for j in range(N):
        cost += (n[j] - i )**2
    costlist.append(cost)
ans = min(costlist)
print(ans)