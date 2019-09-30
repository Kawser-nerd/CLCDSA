n = int(input())
price = 0
for i in range(n):
    a, b = map(int, input().split())
    price += a * b
print(int(price * 1.05))