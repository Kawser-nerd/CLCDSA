s = int(input())
h = 0
m = 0
ss = 0
while s >= 3600:
  s-= 3600
  h += 1
if h < 10:
  h = '0{h}'.format(h=h)
while s >= 60:
  s -= 60
  m += 1
if m < 10:
  m = '0{m}'.format(m=m)
while s > 0:
  s -= 1
  ss += 1
if ss < 10:
  ss = '0{ss}'.format(ss=ss)
print("{h}:{m}:{ss}".format(h=h,m=m,ss=ss))