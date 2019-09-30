from collections import Counter
N = int(input())
A = list(map(int,input().split()))
ctr = Counter(A)
maxa = max(A)
mina = min(A)

def ok():
    if mina != (maxa+1)//2:
        return False
    if maxa%2:
        if ctr[mina] != 2: return False
    else:
        if ctr[mina] != 1: return False
    for n in range(mina+1, maxa+1):
        if ctr[n] < 2:
            return False
    return True

print('Possible' if ok() else 'Impossible')