import sys

def pairize(L):
    return [(L[i], L[i+1]) for i in range(0, len(L), 2)]
        
def max_boxed(listA, listB, indA=0, indB=0, amtA=None, amtB=None, M={}):
    if (indA, indB, amtA, amtB) in M:
        # print 'hit'
        return M[(indA, indB, amtA, amtB)]
    if indA == len(listA) or indB == len(listB):
        return 0
    (a, A) = listA[indA]
    (b, B) = listB[indB]
    if amtA is not None:
        a = amtA
    if amtB is not None:
        b = amtB
    # print listA, listB
    if A == B:
        if a >= b:
            ret = b + max_boxed(listA, listB, indA, indB+1, amtA=a-b, M=M)
        else:
            ret = a + max_boxed(listA, listB, indA+1, indB, amtB=b-a, M=M)
    else:
        for i in range(indB, len(listB)):
            if listB[i][1] == A:
                nextB = i
                break
        else:
            nextB = len(listB)
        ret = max(max_boxed(listA, listB, indA, nextB, amtA=amtA, M=M),
                   max_boxed(listA, listB, indA+1, indB, amtB=amtB, M=M))
    M[(indA, indB, amtA, amtB)] = ret
    return ret

fi = open("C.in", "r")
fo = open("C.out", "w")

T = int(fi.readline())
for case in range(T):
    N, M = map(int, fi.readline().split())
    listA = pairize(map(int, fi.readline().split()))
    listB = pairize(map(int, fi.readline().split()))
    result = max_boxed(listA, listB, M={})
    fo.write('Case #{0}: {1}\n'.format(case+1, result))

print "Done"
fo.flush()
