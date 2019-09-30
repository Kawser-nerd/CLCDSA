import bisect
import sys
def input(): return sys.stdin.readline()
def inpl(): return [int(i) for i in input().split()]
def lis(L):
    seq = [L[0]]
    for i in L[1:]:
        if seq[-1] < i:
            seq.append(i)
        else:
            seq[bisect.bisect_left(seq, i)] = i
    return len(seq)

N = int(input())
Box = [inpl() for _ in range(N)]
Box.sort(key = lambda x:(x[0], -x[1]))
Box = [y for x, y in Box]
print(lis(Box))