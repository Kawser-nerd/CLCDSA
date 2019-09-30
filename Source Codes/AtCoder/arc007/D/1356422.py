#!/usr/bin/env python3
c = input()
n = len(c)
idx = 1
while idx < n and c[idx] == '0':
        idx += 1
if c[0] != '0':
        a = int(c[0:idx:])
else:
        a = int('1' + c[0:idx:])
c = c[idx::]
d = -1
if c == "":
        d = 1
else:
        nc = c
        while True:
                ok = False
                for i in range(10):
                        tmp = nc + str(i)
                        diff = int(tmp) - a
                        if diff >= 1:
                                ok = True
                                d = diff
                                break
                if ok:
                        break
                else:
                        nc = nc + str('0')
n = len(c)
for i in range(1, n + 1):
        ok = True
        e = int(c[0:i]) - a
        if e <= 0:
                continue
        cur = a + e
        j = i
        while j < n:
                cur += e
                tar = str(cur)
                for k in range(len(tar)):
                        if j == n:
                                break
                        if tar[k] != c[j]:
                                ok = False
                        j += 1
        if ok:
                d = min(d, e)
print(a, d)