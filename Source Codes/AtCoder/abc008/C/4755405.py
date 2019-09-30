import math
n = int(input())
num = [int(input()) for i in range(n)]

def g(x,n):
     c = int((x//2+1)*math.factorial(n)//(x+1))
     return c
     
count = 0
for i in num:
     yakusu = 0
     for j in num:
          if i%j == 0:
               yakusu += 1
     count += g(yakusu-1,n)
          
print(count/(math.factorial(n)))