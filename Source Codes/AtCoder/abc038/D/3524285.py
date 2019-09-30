N = int(input())
box = [tuple(map(int,input().split())) for i in range(N)]
box = sorted(box,key=lambda x:(x[0],-x[1]))
L = [x[1] for x in box]

from bisect import bisect_left
def LIS(L):
    seq = []
    for a in L:
        i = bisect_left(seq,a)
        if len(seq) == i:
            seq.append(a)
        else:
            seq[i] = a
    return len(seq)

print(LIS(L))