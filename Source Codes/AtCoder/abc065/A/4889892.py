x, a, b = map(int, input().split())
ans = 'delicious' if a - b >= 0 else 'safe' if (b - a) <= x else 'dangerous'
print(ans)