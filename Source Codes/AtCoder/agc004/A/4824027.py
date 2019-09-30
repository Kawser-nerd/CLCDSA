a, b, c = map(int, input().split())
print(min(min(a*b, b*c), c*a) if a%2 and b%2 and c%2 else 0)