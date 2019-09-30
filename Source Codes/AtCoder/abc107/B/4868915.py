import numpy as np
h,w = map(int,input().split())
a_list = [list(input()) for _ in range(h)]
res = []
for a in a_list:
    if set(a) != set('.'):
        res.append(a)
res = list(np.array(res).T)
resT = []
for a in res:
    if set(a) != set('.'):
        resT.append(a)
for a in list(np.array(resT).T):
    print(''.join(a))