N = int(input())
h = N // 3600
N = N % 3600
m = N // 60
s = N % 60
h = str(h)
m = str(m)
s = str(s)
if len(h) == 1:
    h = '0' + h
if len(m) == 1:
    m = '0' + m
if len(s) == 1:
    s = '0' + s
print(':'.join([h,m,s]))