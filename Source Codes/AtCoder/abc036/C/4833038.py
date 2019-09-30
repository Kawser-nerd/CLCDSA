n=int(input())
A=[[i,int(input())] for i in range(n)]

A=sorted(A,key=lambda x:x[1])
cnt=0
A[0].append(0)
for i in range(1,n):
    if A[i-1][1]!=A[i][1]:
        cnt+=1
    A[i].append(cnt)
A=sorted(A,key=lambda x:x[0])
for i in range(n):
    print(A[i][2])