n, m = map(int, input().split())
n = n % 12
n = (n * 5) + (m/60)*5
ans = min(abs(n-m), 60-abs(n-m))
ans *= 6
print(ans)