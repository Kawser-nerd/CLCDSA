from itertools import combinations

def solve():
    s = input()
    patlen = len(s)
    pat = [(i=='o') for i in s]
    pat = pat*2
    for i in range(patlen+1):
        for j in combinations(list(range(patlen)),i):
            zure = [[] for _ in range(i)]
            for k in range(i):
                zure[k] = pat[j[k]:j[k]+patlen]

            newpat = [False]*patlen
            for pl in range(patlen):
                for j in range(i):
                    newpat[pl] |= zure[j][pl]

            if not False in newpat: return i

print(solve())