n = int(input())
a = [int(input()) for _ in range(n)]
a.append(0) #?????
donnyoku = 0
for i in range(n):
  pair = (a[i]+a[i+1])//2
  donnyoku += pair
  a[i+1] -= max(0,2*pair-a[i])
print(donnyoku)