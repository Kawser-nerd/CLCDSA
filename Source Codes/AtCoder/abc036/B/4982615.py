# ??
N=int(input())

l=[]
for i in range(N):
  l.append(input())

for i in range(N):
  s=''
  for j in range(N)[::-1]:
    s+=l[j][i]
  print(s)