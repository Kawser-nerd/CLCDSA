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
keta =0
for i in range(1,n+1):
  teisu = (teisu*i)/4
  if teisu > 10**10:
    teisu = teisu/(10**10)
    keta = keta+10

def factorial_calc(num):
  res = 1
  keta1 = 0
  for i in range(1,num+1):
    res = res*i
    if res >10**10:
      res = res/(10**10)
      keta1 = keta1+10
  return res
    
def keta_calc(num):
  res = 1
  keta1 = 0
  for i in range(1,num+1):
    res = res*i
    if res >10**10:
      res = res/(10**10)
      keta1 = keta1+10
  return keta1

for nokori_x_times in range(0,nokori+1,2):
  ans = ans +  (10**(keta-keta_calc(nokori_x_times//2)-keta_calc(x_times+nokori_x_times//2)-keta_calc(y_times+(nokori-nokori_x_times)//2)-keta_calc((nokori-nokori_x_times)//2)))/factorial_calc(nokori_x_times//2)/factorial_calc(x_times+nokori_x_times//2)/factorial_calc(y_times+(nokori-nokori_x_times)//2)/factorial_calc((nokori-nokori_x_times)//2)

print(ans*teisu)