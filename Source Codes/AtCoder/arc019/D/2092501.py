# seishin.py
N = 150
p = 13
cnt = 0
print(N)
for l in range(N):
    i = l // p
    j = l % p
    tmp = ['.']*(p**2)
    for k in range(p):
        tmp[p*k+((i*k+j)%p)] = 'O'
    print(*tmp[:N], sep='')