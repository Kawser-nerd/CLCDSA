import sys

sys.stdin = open("A-large.in", "r")

nn = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

tn = int(input())
for test in range(1, tn + 1):
    s = input()
    v = {}
    for x in s:
        if x not in v:
            v[x] = 0
        v[x] += 1
    cnt = [0] * 10
    used = set()
    while len(used) < 10:
        for x in nn:
            if x not in used:
                good = '$'
                for t in x:
                    canT = True
                    for z in nn:
                        if z not in used and z != x and t in z:
                            canT = False
                    if canT:
                        good = t
                        break
                if good != '$':
                    used.add(x)
                    for z in range(len(nn)):
                        if nn[z] == x:
                            ind = z
                            break
                    if good in v:
                        cnt[z] = v[good]
                        for c in x:
                            if c in v:
                                v[c] -= cnt[z]
    print("Case #%d:" % test, "".join([str(x) * cnt[x] for x in range(10)]))
