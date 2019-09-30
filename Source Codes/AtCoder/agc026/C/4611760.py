n = int(input())
s = list(input())
l = s[:n]
r = list(reversed(s[n:]))
hashl = {}
hashr = {}
for i in range(1 << n):
    llr = []
    llb = []
    lrr = []
    lrb = []
    for k in range(n):
        if i & (1 << k):
            llr.append(l[k])
            lrr.append(r[k])
        else:
            llb.append(l[k])
            lrb.append(r[k])
    sl = (''.join(llr), ''.join(llb))
    sr = (''.join(lrr), ''.join(lrb))

    if sl not in hashl: hashl[sl] = 1
    else: hashl[sl] += 1
    if sr not in hashr: hashr[sr] = 1
    else: hashr[sr] += 1
ret = 0
for strpair, c in hashl.items():
    if strpair in hashr:
        ret += hashr[strpair] * c
print(ret)