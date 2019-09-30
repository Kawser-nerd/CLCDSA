n,m=[int(val) for val in input().split()]
matrix=[[int(val) for val in input().split()]for val in range(m)]
#print(n,m,matrix)
ee=[[val[0]-1, val[1]-1] for val in matrix]

cnt=0
k=0
for L in range(m):
    xx=[i for i in range(n)]
    for j in range(m):
        if j!=k:
            val1=xx[ee[j][1]]
            val2=xx[ee[j][0]]
            for i in range(len(xx)):
                if xx[i]==val1:
                    xx[i]=val2
#    print(xx)
    if len(set(xx))>1:
        cnt+=1
    k+=1
    
print(cnt)