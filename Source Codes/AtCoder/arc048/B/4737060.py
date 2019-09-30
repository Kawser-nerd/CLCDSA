N=int(input())
L=[[0,0,0]for i in range(100001)]

M=[]

for i in range(N):
    R,H=map(int,input().split())
    M.append([R,H-1])
    L[R][H-1]+=1
    
S=[0]
for i in range(1,100001):
    S.append(S[i-1]+L[i][0]+L[i][1]+L[i][2])
    
for i in range(N):
    if M[i][1]==0:
        e=L[M[i][0]][0]-1
        w=L[M[i][0]][1]+S[M[i][0]-1]
    elif M[i][1]==1:
        e=L[M[i][0]][1]-1
        w=L[M[i][0]][2]+S[M[i][0]-1]
    elif M[i][1]==2:
        e=L[M[i][0]][2]-1
        w=L[M[i][0]][0]+S[M[i][0]-1]
    l=N-1-e-w
    print(w,l,e)