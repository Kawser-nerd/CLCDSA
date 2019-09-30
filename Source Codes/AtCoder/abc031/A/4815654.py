a, d = map(int, input().split())
ans = max((a+1)*d, (d+1)*a)
print(ans)