n, m = map(int, input().split())
xlist = list(map(int, input().split()))
ylist = list(map(int, input().split()))

xsum = 0
for i, x in enumerate(xlist):
  xsum += i * x - (n - i - 1) * x

ysum = 0
for i, y in enumerate(ylist):
  ysum += i * y - (m - i - 1) * y

print(xsum * ysum % 1000000007)