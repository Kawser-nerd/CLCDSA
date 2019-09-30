x, a, b = map(int, input().split())

print("delicious" if b <= a else "dangerous" if x + a < b else "safe")