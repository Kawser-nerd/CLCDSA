N = int(input())
L = list(map(int,input().split()))
L.sort(reverse=1)
length = 0

for i in range(1,N):
  length += L[i]
  
if L[0]<length:
  print("Yes")
else:
  print("No")