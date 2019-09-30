n, x = map(int, input().split())
a = list(map(int, input().split()))

x_bin = bin(x)[2:][::-1]
sum_price = 0

for i in range(len(x_bin)):
    if x_bin[i] == "1":
        sum_price += a[i]

print(sum_price)