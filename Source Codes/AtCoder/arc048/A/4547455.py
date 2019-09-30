a, b = map(int, input().split())
print(b-a-1 if a*b<0 else b-a)