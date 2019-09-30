N = int(input())
S = [input() for i in range(N)]
from collections import Counter
dic = Counter(" ".join(S).split())
print(dic.most_common(1)[0][0])