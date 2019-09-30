N = int(input())
A = list(map(int,input().split()))
Color = [0]*9

for i in range(N):
  for j in range(9):
    if(j == 0):
      if(1<=A[i]<400): Color[j] = 1 
    elif(1<=j<=7):
       if(400*j<=A[i]<400*(j+1)):Color[j] = 1
    else:
       if(3200<=A[i]): Color[j] += 1
   

if(N == Color[-1]):
  ans_min = 1
  ans_max = N
else:
  ans_min = sum(Color) - Color[-1]
  ans_max = sum(Color) 
print(ans_min,ans_max)