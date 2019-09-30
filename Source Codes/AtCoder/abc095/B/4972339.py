N,M=map(int,input().split())
L=[]
for i in range(N) :
  L.append(int(input()))
print(N+(M-sum(L))//min(L))