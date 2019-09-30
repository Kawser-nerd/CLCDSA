N = int(input())
hh = int(N / 3600 % 24)
mm = int(N / 60 % 60)
ss = N % 60
print(str(hh).zfill(2) + ':' + str(mm).zfill(2) + ':' + str(ss).zfill(2))