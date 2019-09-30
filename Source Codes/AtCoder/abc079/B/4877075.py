N=int(input())
L=[2,1] 
for i in range(N-1) :
  A=L[i]+L[i+1]
  L.append(A)
print(L[-1])