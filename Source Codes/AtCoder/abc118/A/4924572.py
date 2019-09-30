A, B = map(int, input().split())
print([A + B, B - A][not(B % A == 0)])