import sys
n,m=map(int,input().split())
a=[list(map(int,input().split())) for i in range(n)]
for i in range(n):
    for j in range(m):
        a[i][j]-=1
itr=[0 for i in range(n)]
opend=[True for i in range(m)]
back=[[] for i in range(m)]
for i in range(n):
    back[a[i][0]].append(i)
ret=10**9
while True:
    tmp=0
    for i in range(m):
        tmp=max(tmp,len(back[i]))
    ret=min(ret,tmp)
    for i in range(m):
        if len(back[i])>=ret:
            opend[i]=False
            for j in range(len(back[i])):
                source=back[i][j]
                while not opend[a[source][itr[source]]]:
                    itr[source]+=1
                    if itr[source]==m:
                        print(ret)
                        sys.exit()
                back[a[source][itr[source]]].append(source)
            back[i]=[]