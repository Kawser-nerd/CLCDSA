N,M = map(int,input().split())
src = list(map(lambda x:int(x)-1,input().split()))

imos = [0] * (2*M+1)
ends = [0] * (2*M+1)
max_press = 0
for a,b in zip(src,src[1:]):
    if a > b:
        b += M
    if b-a > 1:
        imos[a+2] += 1
        imos[b+1] -= 1
        ends[b+1] += b-a-1
    max_press += b-a

for i in range(2*M):
    imos[i+1] += imos[i]

press = [max_press] * M
d = 0
for i,(dec,inc) in enumerate(zip(imos, ends)):
    d += inc - dec
    press[i%M] += d
print(min(press))