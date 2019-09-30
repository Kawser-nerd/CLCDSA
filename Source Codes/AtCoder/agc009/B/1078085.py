from collections import Counter

n = int(input())
xs = [None] + [int(input())-1 for _ in range(n-1)]

count_win = Counter(xs)
q = [i for i in range(n) if not i in count_win]
children = [[] for i in range(n)]

qi = 0
while not q[qi]==0:
    i, qi = q[qi], qi+1
    children[i].sort(reverse=True)
    children[i] = max(v+w for v, w in  enumerate([0]+children[i]))
    j = xs[i]
    children[j].append(children[i])
    if count_win[j] <= 1:
        q.append(j)
    else:
        count_win[j] -= 1

children[0].sort(reverse=True)
children[0] = max(v+w for v, w in  enumerate([0]+children[0]))

print(children[0])