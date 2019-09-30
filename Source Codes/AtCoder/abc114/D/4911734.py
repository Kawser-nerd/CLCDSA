N=int(input())
pdic={2:0}
for i in range(3,50,2):
    for j in pdic.keys():
        if i%j==0:
            break
    else:
        pdic[i]=0
for i in range(2,N+1):
    for p in pdic.keys():
        while i%p==0:
            pdic[p]+=1
            i//=p
ge={i:sum(x>=i-1 for x in pdic.values()) for i in (3,5,15,25,75)}
if ge[5]<2 and ge[3]<3:
    print(0)
else:
    print(ge[5]*(ge[5]-1)//2*(ge[3]-2)+ge[25]*(ge[3]-1)+ge[15]*(ge[5]-1)+ge[75])