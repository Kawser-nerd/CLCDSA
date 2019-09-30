n,c=map(int,input().split()) 
d=[[] for i in range(c)]
for i in range(c):
    d[i]=list(map(int,input().split()))
mat=[[] for i in range(n)]
cl=[[] for i in range(3)]
for i in range(n):
    mat[i]=list(map(int,input().split()))
for i in range(n):
    for j in range(n):
        if (i+j)%3==0:
            k=0
        elif (i+j)%3==1:
            k=1
        else:
            k=2
        cl[k].append(mat[i][j])
q=[[0 for i in range(c)] for i in range(3)]
for i in range(c):
    for j in range(3):
        for k in cl[j]:
            q[j][i]+=d[k-1][i]            
mi=10**9
for i in range(c):
    for j in range(c):
        for k in range(c):
            if i!=j and j!=k and k!=i:
                s=q[0][i]+q[1][j]+q[2][k]
                if s<mi:
                    mi=s
print(mi)