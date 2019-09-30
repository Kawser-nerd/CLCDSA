a, b = int(input()), int(input())
print(min(abs(a - b), abs((10 - max(a, b)) + min(a, b))))