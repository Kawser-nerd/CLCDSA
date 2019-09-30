# not solved only by myself
N = int(input())

def get_nums(wa,ar):
    ar = sorted(ar,reverse=True)
    tmp = 0
    for a in ar:
        tmp += wa // a
        wa %= a
    return tmp + wa


nines = []
tmp = 9
while tmp <= N:
    nines.append(tmp)
    tmp *= 9

sixes = []
tmp = 6
while tmp <= N:
    sixes.append(tmp)
    tmp *= 6



res = N
for t in range(0,N + 1):
    hoge = get_nums(t,sixes) + get_nums(N - t,nines)
    res = min(res,hoge)

print(res)