A1, A2, A3 = map(int, input().split())
print(min(abs(A1 - A2) + abs(A2 - A3), abs(A1 - A2) + abs(A1 - A3), abs(A2 - A3) + abs(A3 - A1)))