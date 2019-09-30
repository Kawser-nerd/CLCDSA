N = int(input())
import sys

all_list = []
counter = 1
for line in sys.stdin:
    a, b = [int(x) for x in line.strip().split(" ")]
    all_list += [("a", counter, a), ("b", counter, b)]
    counter += 1

all_list = sorted(all_list, key = lambda x : x[2])

sp_c = all_list[N][1]
sp_i_p = all_list[N][2]
sp_i_pp = all_list[N+1][2]

flag = True
ss = sum([i[2] for i in all_list[:N]])
d = set()
temp = None
for ab, c, i in all_list[:N]:
    if temp != None and temp != ab:
        flag = False
    if c in d:
        flag = True
        break
    d.add(c)
    temp = ab
if flag:
    print(ss)
else:
    candidates = []
    for ab, c, i in all_list[:N]:
        if sp_c != c:
            candidates.append(ss - i + sp_i_p)
        else:
            candidates.append(ss - i + sp_i_pp)
    print(min(candidates))