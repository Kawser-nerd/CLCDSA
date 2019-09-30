import collections
import math
N = int(input())
Ss = [input() for i in range(N)]
counter=collections.Counter(Ss).most_common()
print(counter[0][0])