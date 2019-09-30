import sys

a, b, c, x, y = map(int, input().split())

price = 0
another = sys.maxsize

if 2*c < a + b:
    price += 2 * c * min(x, y)
    another = 2 * c * max(x, y)
    if x > y:
        price += (x - y) * a
    else:
        price += (y - x) * b
else:
    price = a * x + b * y
    
print(price) if another > price else print(another)