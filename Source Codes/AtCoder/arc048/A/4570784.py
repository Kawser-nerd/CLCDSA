A, B = map(int, input().split())

print(B - A - 1 if A * B < 0 else B - A)