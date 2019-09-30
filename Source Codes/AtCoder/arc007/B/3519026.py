n,m=map(int,input().split())
d={i:i for i in range(n+1)}

for _ in range(m):
  disk=int(input())
  pos=[i for i,j in d.items() if j==0][0]
  d[disk],d[pos]=d[pos],d[disk]

for i,j in sorted(d.items(),key=lambda x:x[1])[1:]:
  print(i)