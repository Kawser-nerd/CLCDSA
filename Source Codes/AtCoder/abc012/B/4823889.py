N = int(input())

h, m = N//3600, N%3600
m, s = m//60, m%60

print('{}:{}:{}'.format(str(h).zfill(2), str(m).zfill(2), str(s).zfill(2)))