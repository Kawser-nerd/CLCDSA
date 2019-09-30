N = int(input())
F=[]
for i in range(N):
    F.append(list(map(int,input().split())))

P=[]
for i in range(N):
    P.append(list(map(int, input().split())))

B=[bin(i)[2:] for i in range(1024)]
for i in range(len(B)):
    while(len(B[i])<10):
        B[i]="0"+B[i]
c=0
ans=-10**9
for b in B[1:]:
    res=0
    for index,f in enumerate(F):
        #print('f',f)
        for i,j in zip(f,b):
            if(str(i)==j and i==1):
                c+=1
        #print(b,"????c:",c)
        #print("p",P[index][c])
        res+=P[index][c]
        c=0
    ans=max(ans,res)
print(ans)