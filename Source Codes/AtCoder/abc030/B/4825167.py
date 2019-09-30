n, m = map(int, input().split())
n2 = (n % 12)*5 + m*5/60.0
d = abs(n2*6 - m*6)
print(min(d, 360-d))