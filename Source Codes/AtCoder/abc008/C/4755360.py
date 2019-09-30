n = int(input())
num = [int(input()) for i in range(n)]

ans = 0
for i in num:
     yakusu =0
     for j in num:
          if i%j == 0:
               yakusu +=1
     ans += ((yakusu+1)//2)/yakusu
          
print(ans)