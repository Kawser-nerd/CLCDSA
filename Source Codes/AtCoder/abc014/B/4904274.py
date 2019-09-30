[n,x] = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
price = 0
s = bin(x)[2:]
#print(s)
for i in range(len(s)-1,-1,-1):
  if s[len(s) - 1 - i] == "1":
    #print(a[i])
    price += a[i]
print(price)