def p(w,r,m,c=1):
    n=d.index(w[r])+d.index(w[r-c])+x.index(m)
    return d[n%2]

a=['SS','SW','WS','WW']
d=['S','W']
x=['o','x']

n=int(input())
s=input()
for j in range(4):
    for i in range(1,n):
        a[j]+=p(a[j],i,s[i])
    a[j]=p(a[j],0,s[0],-1)+a[j]

ans=-1
for w in a:
    if w[0]==w[-2] and w[1]==w[-1]:
        ans=w[1:-1]
print(ans)