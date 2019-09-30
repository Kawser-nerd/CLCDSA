import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        C, J = f.readline().split()

        def score((c, j)):
            assert len(c) == len(j)
            c = int(c)
            j = int(j)
            return (abs(c - j), c, j)

        def tryall(c, j, totry):
            results = []
            for nc, nj, ne in totry:
                bc, bj = run(c[1:], j[1:], ne)
                results.append((nc + bc, nj + bj))
            return min(results, key=score)

        def run(c, j, larger):
            if not c:
                return "", ""
            fc = c[0]
            fj = j[0]
            if fc != '?' and fj != '?':
                new_larger = larger
                if larger == 'e':
                    nc = int(fc)
                    nj = int(fj)
                    if nc > nj:
                        new_larger = 'c'
                    elif nc < nj:
                        new_larger = 'j'
                bc, bj = run(c[1:], j[1:], new_larger)
                return (fc + bc, fj + bj)
            if fc == '?' and fj == '?':
                if larger == 'c':
                    bc, bj = run(c[1:], j[1:], larger)
                    return ('0' + bc, '9' + bj)
                if larger == 'j':
                    bc, bj = run(c[1:], j[1:], larger)
                    return ('9' + bc, '0' + bj)

                return tryall(c, j, [('0', '0', 'e'), ('1', '0', 'c'), ('0', '1', 'j')])
                # bce, bje = run(c[1:], j[1:], 'e')
                # bcc, bjc = run(c[1:], j[1:], 'c')
                # bcj, bjj = run(c[1:], j[1:], 'j')
# 
                # return min([('0' + bce, '0' + bje), ('1' + bcc, '0' + bjc), ('0' + bcj, '1' + bjj)], key=score)

            if fc == '?':
                assert fj != '?'
                if larger == 'e':
                    totry = [(fj, fj, 'e')]
                    if fj != '9':
                        totry.append((chr(ord(fj) + 1), fj, 'c'))
                    if fj != '0':
                        totry.append((chr(ord(fj) - 1), fj, 'j'))
                    return tryall(c, j, totry)
                if larger == 'j':
                    bc, bj = run(c[1:], j[1:], larger)
                    return ('9' + bc, fj + bj)
                if larger == 'c':
                    bc, bj = run(c[1:], j[1:], larger)
                    return ('0' + bc, fj + bj)
                assert 0, (c, j, larger)
            if fj == '?':
                assert fc != '?'
                if larger == 'e':
                    totry = [(fc, fc, 'e')]
                    if fc != '9':
                        totry.append((fc, chr(ord(fc) + 1), 'j'))
                    if fc != '0':
                        totry.append((fc, chr(ord(fc) - 1), 'c'))
                    return tryall(c, j, totry)
                if larger == 'c':
                    bc, bj = run(c[1:], j[1:], larger)
                    return (fc + bc, '9' + bj)
                if larger == 'j':
                    bc, bj = run(c[1:], j[1:], larger)
                    return (fc + bc, '0' + bj)
                assert 0, (c, j, larger)
            assert 0, (c, j, larger)

        # _run = run
        # def run(*args):
            # r = _run(*args)
            # print "%s: %s" % (args, r)
            # return r

        best_c, best_j = run(C, J, 'e')
        print "Case #%d: %s %s" % (_T + 1, best_c, best_j)
