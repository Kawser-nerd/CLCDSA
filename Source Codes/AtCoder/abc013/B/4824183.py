a = int(input())
b = int(input())

x_min = min(a, b)
x_max = max(a, b)

print(min(x_max - x_min, x_min + 9-x_max + 1))