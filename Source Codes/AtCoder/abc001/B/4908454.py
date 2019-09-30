import sys

m = int(input())
d = 0

if m < 100:
    d = 0
elif m <= 5000:
    d = m/100
elif m <= 30000:
    d = m/1000 + 50
elif m <=70000:
    d = (m/1000-30)/5+80
elif m > 70000:
    d = 89

print("%02d" % d )