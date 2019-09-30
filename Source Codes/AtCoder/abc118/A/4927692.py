a, b = map(int, input().split())
print(a+b if b%a == 0 else b-a)