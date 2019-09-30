n=int(input())
se=[list(map(int,input().split("-"))) for _ in range(n)]
for i in range(n):
    se[i][0]+=10000
    se[i][1]+=10000
    se[i][0]-=se[i][0]%5
    if se[i][1]%5!=0:
        se[i][1]+=5-se[i][1]%5
    if se[i][1]%100==60:
        se[i][1]+=40
se=sorted(se, key=lambda x:x[0])
res=[se[0]]
for t in se:
    if res[-1][1]<t[0]:
        res.append(t)
    elif res[-1][1]<t[1]:
        res[-1][1]=t[1]
for t in res:
    a=[str(t[0])[1::],str(t[1])[1::]]
    print("-".join(a))