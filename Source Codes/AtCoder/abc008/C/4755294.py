import math
n = int(input())
num = [int(input()) for i in range(n)]

def f(i,num):
     cou = 0
     for j in range(n):
          if num[i]%num[j] == 0:
               cou += 1
     return cou-1

def g(x,n):
     c = (x//2+1)*math.factorial(n)//(x+1)
     return c
     
memo = ["#"]*n
count = 0
for i in range(0,n):
     number = num[i]
     yakusu = f(i,num)
     if memo[yakusu] != "#":
          count += memo[yakusu]
     else:
          comb = g(yakusu,n)
          count += comb
          memo[yakusu] = comb
          
ans = count/(math.factorial(n))
print(ans)