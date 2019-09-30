n = int(input())
amount = 0
for i in range(n):
    a , b = map(str,input().split())
    x = float(a)
    if b=="JPY":
        amount = amount + x
    else:
        amount = amount + x*380000.0
print(amount)