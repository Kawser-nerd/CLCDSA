L,N = list(map(int,input().split()))
X=[]
Y=[]
SX=[0]
SY=[0]
sx=0
sy=0
for i in range(N):
   x=int(input())
   X.append(x)
   sx+=x
   SX.append(sx)
   Y.append(L-x)
   sy+=L-x
   SY.append(sy)   

max_score=0   
for i in range(N):
    if i>N-i-1:
        max_score=max(2*(SX[i]-SX[2*i-N])+2*(SY[N]-SY[i+1])+Y[i],max_score)
    elif i<N-i-1:
        max_score=max(2*(SX[i]-SX[0])+2*(SY[2*i+2]-SY[i+1])+X[i],max_score)

        
    ind = min(i,N-i-1)
    max_score=max(2*(SX[i]-SX[i-ind])+2*(SY[i+ind+1]-SY[i+1])+X[i],max_score)
    max_score=max(2*(SX[i]-SX[i-ind])+2*(SY[i+ind+1]-SY[i+1])+Y[i],max_score)


print(max_score)
#copy code.