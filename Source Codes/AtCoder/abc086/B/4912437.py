import math


a, b = input().split()
print('Yes' if math.sqrt(int(a + b)) % 1 == 0 else 'No')