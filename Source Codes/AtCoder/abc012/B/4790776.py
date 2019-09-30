n = int(input())
h = 0
m = 0
s = 0
while n >= 3600:
    n -= 3600
    h += 1
while n >= 60:
    n -= 60
    m += 1
s += int(n)
print("{:0>2}:{:0>2}:{:0>2}".format(h, m, s))