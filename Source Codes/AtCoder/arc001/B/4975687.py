n=int(input())
c=list(input())
M=[0,n]
for i in range(1,5):
  M=[max(M[0],c.count(str(i))),min(M[1],c.count(str(i)))]
print(*M)