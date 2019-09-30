import math
n = int(input())
x = 1
num = len(bin(n))-2

if num %2 ==0:
  while True:
    x =2*x
    if x > n:
      print("Aoki")
      exit()
    x =2*x+1
    if x > n:
      print("Takahashi")
      exit()
else:
  while True:
    x =2*x+1
    if x > n:
      print("Aoki")
      exit()
    x =2*x
    if x > n:
      print("Takahashi")
      exit()