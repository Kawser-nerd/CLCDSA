import math
n,d = map(int,input().split())
x,y = map(int,input().split())
if x%d!=0 or y%d!=0:
  print(0)
  exit()
x_times = abs(x)//d
y_times = abs(y)//d
nokori = n - x_times - y_times
if nokori < 0 or nokori%2 ==1:
  print(0)
  exit()
ans = 0

teisu = 1
for i in range(1,n+1):
  teisu = teisu*i


for nokori_x_times in range(0,nokori+1,2):
  ans = ans +  teisu//(math.factorial(nokori_x_times//2)*math.factorial(x_times+nokori_x_times//2)*math.factorial(y_times+(nokori-nokori_x_times)//2)*math.factorial((nokori-nokori_x_times)//2))
print(ans/(4**n))