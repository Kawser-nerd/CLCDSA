n,c=map(int, input().split())
a=[[0,0]]+[list(map(int, input().split())) for i in range(n)]+[[c,0]]
m=[0]
h=[0]
mb=[0]
hb=[0]
for i in range(n+1):
    m.append(m[-1]-a[i+1][0]+a[i][0]+a[i+1][1])
    mb.append(m[-2]-a[i+1][0]+a[i][0]+a[i+1][1]-a[i+1][0])
    h.append(h[-1]-a[-i-1][0]+a[-i-2][0]+a[-i-2][1])
    hb.append(h[-2]-a[-i-1][0]+a[-i-2][0]+a[-i-2][1]-c+a[-i-2][0])

mm=[0]
for i in range(n):
    mm.append(max(mm[-1],m[i+1]))
hm=[0]
for i in range(n):
    hm.append(max(hm[-1],h[i+1]))
    
ans=max(hm[-1],mm[-1])
for i in range(1,n):
    ans=max(hb[i]+mm[-i-1], mb[i]+hm[-i-1],ans)
print(ans)