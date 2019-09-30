#!/usr/bin/env python

from collections import defaultdict

def tryint(x):
    try:
        return int(x)
    except ValueError:
        return x

def readline():
    return map(tryint, raw_input().strip().split())

def pairwise(it):
    it = iter(it)
    a = next(it, None)
    for b in it:
        yield a, b
        a = b

def solve():
    n, = readline()
    door = []
    anon = []
    face = defaultdict(list)
    for i in xrange(n):
        a, f = readline()
        door.append([a == 'E', f])
        if f == 0:
            anon.append((a == 'E', i))
        else:
            face[f].append((a == 'E', i))

    need = []
    for f, actions in face.iteritems():
        for a1, a2 in pairwise(actions):
            if a1[0] == a2[0]:
                need.append((not a1[0], a1[1], a2[1], f))

    for a, i in anon:
        fit = [(na, ni, nj, nf) for na, ni, nj, nf in need if a == na and ni < i < nj]
        if not fit:
            continue
        z = min(fit, key=lambda (na, ni, nj, nf): nj)
        need.remove(z)
        door[i][1] = z[3]
    
    if need:
        return "CRIME TIME"

    faces = set()
    nf = 0
    na = 0
    for a, f in door:
        if f > 0:
            if a:
                faces.add(f)
                nf += 1
            else:
                if f in faces:
                    faces.remove(f)
                    nf = max(nf - 1, 0)
                    if nf == 0:
                        faces = set()
                else:
                    na = max(na - 1, 0)
        else:
            if a:
                na += 1
            else:
                if nf > 0:
                    nf -= 1
                    if nf == 0:
                        faces = set()
                else:
                    na = max(na - 1, 0)
    return nf + na



def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
