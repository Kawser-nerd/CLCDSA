import sys

m = int(sys.stdin.readline())

ans = 0

if 100 <= m <= 5000:
    ans = m / 100
elif 6000 <= m <= 30000:
    ans = m / 1000 + 50
elif 35000 <= m <= 70000:
    ans = (m / 1000 - 30) / 5 + 80
elif 70000 <= m:
    ans = 89

ans = int(ans)
print("{:02}".format(ans))