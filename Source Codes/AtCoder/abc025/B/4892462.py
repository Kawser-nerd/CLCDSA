n,c,b=map(int,input().split())
a = []
for i in range(n):
    a.append(list(input().split()))

for j in range(n):
    if int(a[j][1])<c:
        a[j][1]=c
    elif int(a[j][1])>b:
        a[j][1]=b
ans=0
for k in range(n):
    if a[k][0]=='East':
        ans += int(a[k][1])
    elif a[k][0]=='West':
        ans -= int(a[k][1])



if ans>0:
    print('East',ans)
if ans ==0:
    print(0)
if ans<0:
    print('West',-ans)