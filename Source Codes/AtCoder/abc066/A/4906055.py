a,b,c = map(int, input().split())
print(min(a + b, b + c, c + a))