import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        n, w, l = map(int, f.readline().split())
        students = map(int, f.readline().split())
        assert len(students) == n

        students, indexes = zip(*sorted([(students[i], i) for i in xrange(n)], reverse=True))

        positions = []

        for i in xrange(0, n):
            found = False
            for j in xrange(-1, i):
                if j == -1:
                    x = 0
                else:
                    x = positions[j][0] + students[i] + students[j]
                if x > w:
                    continue
                for k in xrange(-1, i):
                    if k == -1:
                        y = 0
                    else:
                        y = positions[k][1] + students[i] + students[k]
                    if y > l:
                        continue

                    good = True
                    for h in xrange(0, i):
                        _x, _y = positions[h]
                        if (x-_x)**2 + (y-_y)**2 < (students[h] + students[i])**2:
                            good = False
                            break
                    if good:
                        positions.append((x, y))
                        found = True
                        break

                if found == True:
                    break

            assert found

        real_pos = [None] * n
        for i in xrange(n):
            # print i, indexes[i]
            real_pos[indexes[i]] = positions[i]
        # for i in xrange(n):
            # print real_pos[i]

        for i in xrange(n):
            x, y = positions[i]
            assert 0 <= x <= w
            assert 0 <= y <= l
            for j in xrange(i):
                _x, _y = positions[j]
                assert (x-_x)**2 + (y-_y)**2 >= (students[i] + students[j]) ** 2

        print "Case #%d: %s" % (_t+1, ' '.join("%d %d" % p for p in real_pos))
