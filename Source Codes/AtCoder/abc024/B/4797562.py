N,T = list(map(int, input().rstrip().split()))

time = int(input().rstrip()) #?????????A1
total = 0 #?????????????
for i in range(N-1):
    nexttime = int(input().rstrip())
    dif = nexttime-time
    total += dif
    if dif-T > 0:
        total -= dif-T
    time = nexttime
print(total+T)