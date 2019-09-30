N = int(input())

if N//3600:
    hh = N//3600
    N -= hh*3600
else:
    hh = 0
if N//60:
    mm = N//60
    N -= mm*60
else:
    mm = 0
ss = N

print('{}:{}:{}'.format(str(hh).zfill(2), str(mm).zfill(2), str(ss).zfill(2)))