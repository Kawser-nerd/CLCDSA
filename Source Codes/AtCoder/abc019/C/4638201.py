N = int(input())
A = input().split()

def Odds_production(n):
  while(n%2 == 0):
    n = n//2
  return n

for i in range(N):
  A[i] = int(A[i])
  if(A[i]%2 == 0):
    n = Odds_production(A[i])
    A[i] = n
     
A =list(set(A))
print(len(A))