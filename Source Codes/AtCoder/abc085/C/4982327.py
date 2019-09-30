n,y=map(int,input().split())
A=y//10000+1
a=-1
b=-1
c=-1
for i in range(A+1):
  for j in range(n-i+1):
    k=n-i-j
    if i*10000+j*5000+k*1000==y and k>=0:
      a=i
      b=j
      c=k
print(a,b,c)