[a,b,c,k] = [int(i) for i in input().split()]
[s,t] = [int(i) for i in input().split()]
price = 0
if s + t >= k:
  price -= (s+t) * c
price += s * a + t * b
print(price)