n=int(input())
l=[list(map(int,input().split())) for i in range(n)]
ct=0
for i in range(n):
  ct+=l[i][0]*l[i][1]
print(int(ct*1.05))