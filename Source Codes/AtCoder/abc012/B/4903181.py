n = int(input())
h = str(n // 3600)
m = str((n - int(h) * 3600)//60)
s = str((n - int(h) * 3600 - int(m) * 60))
#print(h)
#print(m)
#print(s)
if len(h) == 1:
  h = "0"+h
if len(m) == 1:
  m = "0" + m
if len(s) == 1:
  s = "0" + s
print(h+":"+m+":"+s)