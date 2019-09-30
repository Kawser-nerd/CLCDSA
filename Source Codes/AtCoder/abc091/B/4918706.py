#ABC 091 B - Two Colors Card Game
import collections
n = int(input())
s = [input() for i in range(n)]
m = int(input())
t = [input() for i in range(m)]
c = collections.Counter(s) - collections.Counter(t)
if not c:
    print(0)
else:
    print(c.most_common()[0][1])