n,l,ans=int(input()),list(map(int,input().split())),0;l.sort()
for i in range(n):ans+=l[i*2]
print(ans)