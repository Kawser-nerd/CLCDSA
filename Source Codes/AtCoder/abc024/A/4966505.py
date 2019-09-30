a,b,c,k = map(int,input().split())
s,t = map(int,input().split())

total = s + t
discount = 0
if total >= k:
  discount = total * c

adm = (s * a) + (t * b)

print(adm - discount)