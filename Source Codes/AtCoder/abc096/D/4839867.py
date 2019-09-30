N=int(input())
sosu=[2,3,5,7]
A=[]
M=11
while len(A)<N:
  if all(M%i!=0 for i in sosu):
    sosu.append(M)
    if M%5==1:
      A.append(M)
  M+=2
print(*A)