n, m = (int(i) for i in input().split())

a = (n%12 / 12) * 360 + (m/60)*30
b = (m/60) * 360

x = abs(a-b)
print(min(x, 360-x))