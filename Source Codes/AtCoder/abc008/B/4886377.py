import collections
N = int(input())
names = [input() for i in range(N)]
max_ele = collections.Counter(names)
print(max_ele.most_common()[0][0])