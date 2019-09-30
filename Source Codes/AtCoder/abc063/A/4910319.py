a, b = map(int, input().split())
ans = a + b if a + b < 10 else 'error'
print(ans)