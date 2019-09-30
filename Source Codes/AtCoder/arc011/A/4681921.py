m,n,N=map(int,input().split())
ct=N
rem=0
while N>=m:
  ct+=(N//m)*n
  rem=N%m
  N=(N//m)*n+rem
print(ct)