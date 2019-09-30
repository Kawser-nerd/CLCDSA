x, a, b = map(int, input().split())
ans = 'A' if abs(x - a) < abs(x - b) else 'B'
print(ans)