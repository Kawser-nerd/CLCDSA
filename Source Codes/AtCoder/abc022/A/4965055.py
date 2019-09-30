n,s,t=map(int,input().split())
w=[int(input()) for _ in range(n)]
c=0
p=0
for i in w:
  p+=i
  if s<=p<=t: c+=1
print(c)