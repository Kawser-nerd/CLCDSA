s = input()
t = input()

d_s2t = dict()
d_t2s = dict()

flg = True
for ss, tt in zip(s, t):
    if d_s2t.get(ss) is None:
        d_s2t[ss] = tt
    else:
        if not d_s2t[ss] == tt:
            flg = False
            break

    if d_t2s.get(tt) is None:
        d_t2s[tt] = ss
    else:
        if not d_t2s[tt] == ss:
            flg = False
            break

if flg:
    if len(set(d_s2t.keys())) != len(set(d_s2t.values())):
        flg = False
    if len(set(d_t2s.keys())) != len(set(d_t2s.values())):
        flg = False

print('Yes' if flg else 'No')