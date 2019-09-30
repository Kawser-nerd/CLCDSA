#!/usr/bin/env python

ORG = "oieastbg"
CHG = "01345789"

def main():
    T = input()
    for t in range(1, T + 1):
        k = input()
        s = raw_input()
        assert k == 2
        n = len(s)
        ps = []
        for i in range(n - 1):
            p = s[i: i + 2]
            ps.append(p)
            if p[0] in ORG:
                j = ORG.index(p[0])
                q = CHG[j] + p[1]
                ps.append(q)
            if p[1] in ORG:
                j = ORG.index(p[1])
                q = p[0] + CHG[j]
                ps.append(q)
            if p[0] in ORG and p[1] in ORG:
                j = ORG.index(p[0])
                k = ORG.index(p[1])
                q = CHG[j] + CHG[k]
                ps.append(q)

        ps = list(set(ps))
        ans = len(ps) + 1

        while ps:
            mark = set()
            mark.add(ps[0][0])
            while True:
                flag = False
                mark2 = set()
                for x in mark:
                    for p in ps:
                        if x in p:
                            i = p.index(x)
                            y = p[1 if i == 0 else 0]
                            if y not in mark:
                                mark2.add(y)
                                flag = True
                if not flag:
                    break
                for y in mark2:
                    mark.add(y)

            din = {}
            dout = {}
            for p in ps:
                if p[0] in mark:
                    din[p[1]] = din.get(p[1], 0) + 1
                    dout[p[0]] = dout.get(p[0], 0) + 1

            odds = 0
            for c in din:
                odds += max(din[c] - dout.get(c, 0), 0)
            if odds > 0:
                odds -= 1

            ans += odds

            ps = filter(lambda p: p[0] not in mark, ps)

        print 'Case #%d: %d' % (t, ans)

if __name__ == '__main__':
    main()
