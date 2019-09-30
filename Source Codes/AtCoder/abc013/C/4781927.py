N,H=list(map(int, input().split()))
A,B,C,D,E = list(map(int, input().split()))

min_cost=A*N

for i in range(0,N+1):
  j = max(0, (N*E - H - i*(B+E))//(D+E) +1)
  k=N-i-j
  # print(i,j,k, H+i*B+j*D-k*E,A*i+C*j) 
  min_cost=min(min_cost, A*i+C*j)
  
print(min_cost)

# ?????????????????????????