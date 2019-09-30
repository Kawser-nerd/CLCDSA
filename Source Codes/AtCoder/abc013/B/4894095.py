a = int(input())
b = int(input())
print(abs(a - b) if abs(a - b) <= 5 else 10 - abs(a - b))