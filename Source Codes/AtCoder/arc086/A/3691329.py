import collections 
def inpl(): return [int(i) for i in input().split()]

N, K = inpl()
A = list(sorted(collections.Counter(inpl()).values()))
if len(A) <= K:
    print(0)
else:
    print(sum(A[:len(A)-K]))