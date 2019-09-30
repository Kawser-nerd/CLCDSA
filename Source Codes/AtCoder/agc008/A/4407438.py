x, y = map(int, input().split())
print(min(a for a in [y - x, y + x + 1, -y - x + 1, -y + x + 2] if a >= 0))