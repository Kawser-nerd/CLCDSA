a, b, c, k = map(int, input().split())
s, t = map(int, input().split())
print(a*s+b*t if s+t < k else a*s+b*t-c*(s+t))