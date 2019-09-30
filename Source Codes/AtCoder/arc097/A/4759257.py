from collections import defaultdict
import string
import itertools

s = input()
k = int(input())

def it(s):
    subs = sorted(s[i:] for i in range(len(s)))
    writed = set()
    for sub in subs:
        for i in range(len(subs)):
            w = sub[:i+1]
            if w not in writed:
                yield w
                writed.add(w)

for ans in itertools.islice(it(s), k-1, k):
    print(ans)