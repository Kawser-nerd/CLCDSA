import collections
N = int(input())
S = [input() for _ in range(N)]
c = collections.Counter(S)
print(c.most_common()[0][0])