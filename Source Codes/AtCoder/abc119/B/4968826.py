n = int(input())
sum = 0
for _ in range(n):
    x,u = input().split()
    if str(u) == "BTC":
        sum += float(x) * 380000.0
    else:
        sum += float(x)
print(sum)