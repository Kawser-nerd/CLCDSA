S = input()
T = input()

ds = dict()
dt = dict()
for i in range(len(S)):
    s, t = S[i], T[i]
    if s in ds:
        if ds[s] != t:
            print('No')
            exit()
    else:
        ds[s] = t

    if t in dt:
        if dt[t] != s:
            print('No')
            exit()
    else:
        dt[t] = s

print('Yes')