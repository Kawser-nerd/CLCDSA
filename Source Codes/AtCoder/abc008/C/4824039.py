n = int(input())
m=[int(input()) for i in range(n)]
a = 0
for i in m:
  y=0
  for j in m:
    if i%j==0:
      y+=1
  a+=(y+1)//2/y
print(a)