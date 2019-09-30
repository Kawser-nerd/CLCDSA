N,M=map(int,input().split())
L=[]
for i in range(N):
  x,y,z=map(int,input().split())
  L.append([x,y,z])
L1=sorted(L,key=lambda x:sum(x))
L2=sorted(L,key=lambda x:x[0]-x[1]+x[2])
L3=sorted(L,key=lambda x:x[0]+x[1]-x[2])
L4=sorted(L,key=lambda x:-x[0]+x[1]+x[2])

ans=[0 for i in range(8)]
X=[0 for i in range(8)]
Y=[0 for i in range(8)]
Z=[0 for i in range(8)]
for i in range(M):
  X[0]+=L1[i][0]
  X[1]+=L1[-i-1][0]
  X[2]+=L2[i][0]
  X[3]+=L2[-i-1][0]
  X[4]+=L3[i][0]
  X[5]+=L3[-i-1][0]
  X[6]+=L4[i][0]
  X[7]+=L4[-i-1][0]
  Y[0]+=L1[i][1]
  Y[1]+=L1[-i-1][1]
  Y[2]+=L2[i][1]
  Y[3]+=L2[-i-1][1]
  Y[4]+=L3[i][1]
  Y[5]+=L3[-i-1][1]
  Y[6]+=L4[i][1]
  Y[7]+=L4[-i-1][1]
  Z[0]+=L1[i][2]
  Z[1]+=L1[-i-1][2]
  Z[2]+=L2[i][2]
  Z[3]+=L2[-i-1][2]
  Z[4]+=L3[i][2]
  Z[5]+=L3[-i-1][2]
  Z[6]+=L4[i][2]
  Z[7]+=L4[-i-1][2]
for i in range(8):
  ans[i]=abs(X[i])+abs(Y[i])+abs(Z[i])
print(max(ans))