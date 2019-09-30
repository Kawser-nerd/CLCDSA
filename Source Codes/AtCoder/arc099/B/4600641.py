A = []
p = 10**18
for i in range(15,2,-1):
  l = max(0,10**(i-3) - 1)
  m = 10**(i-3)
  for j in range(999,9,-1):
    c = l+m*j
    s = c/sum(map(int,str(c)))
    if s-p <= 1e-7:
      A.append(c)
      p = s

for i in range(9,0,-1):A.append(10*i+9)
for i in range(9,0,-1):A.append(i)
A = A[::-1]
A = list(set(A))
A.sort() 


X = int(input())
for i in range(X):print(A[i])