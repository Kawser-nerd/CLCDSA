x, a, b = [int(n) for n in input().split()]

print('A' if abs(x-a) < abs(b-x) else 'B')