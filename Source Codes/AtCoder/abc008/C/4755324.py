n = int(input())
num = [int(input()) for i in range(n)]

def f(i,num):
     c = 0
     for j in range(n):
          if num[i]%num[j] == 0:
               c += 1
     return c-1

ans = 0
for i in range(0,n):
     number, yakusu = num[i], f(i,num)
     ans += (yakusu//2+1)/(yakusu+1)
          
print(ans)