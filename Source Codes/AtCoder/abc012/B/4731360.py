n = int(input())

h = str(n // (60*60))
h = (2-len(h))*"0"+h
m = str((n % (60*60)) // 60)
m = (2-len(m))*"0"+m
s = str((n % (60*60)) % 60)
s = (2-len(s))*"0"+s
print('{}:{}:{}'.format(h, m, s))