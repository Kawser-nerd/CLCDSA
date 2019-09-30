n, m = map(int, input().split())
group=[[i+1] for i in range(n)]   
for i in range(m):
    x, y = map(int, input().split())
    group[x-1].append(y)
    group[y-1].append(x)
ans=1
for i in range(1<<n):
    subgroup=[]
    for j in range(n):
        if i>>j&1==1:
            subgroup.append(j+1)
    if len(subgroup)>ans:
        if (all(all(k in group[j-1] for j in subgroup) for k in subgroup)):
            ans=len(subgroup)
print(ans)