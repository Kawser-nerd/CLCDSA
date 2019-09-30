n=int(input())
t,a=map(int,input().split())
h=list(map(int,input().split()))
f=[]
for i in range(n):
  f.append(abs(a-(t-h[i]*0.006)))
print(f.index(min(f))+1)