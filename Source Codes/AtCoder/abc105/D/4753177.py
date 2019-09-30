def d_candy_distribution(N, M, A):
    import itertools
    import collections
    # A????????M???????????????
    remainders = collections.defaultdict(int)
    for t in [0] + list(itertools.accumulate(A)):
        remainders[t % M] += 1
    # ?????????2????????????2???????????
    return sum([v * (v - 1) // 2 for v in remainders.values() if v >= 2])

N, M = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
print(d_candy_distribution(N, M, A))