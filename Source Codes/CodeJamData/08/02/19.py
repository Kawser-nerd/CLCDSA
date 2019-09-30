import sys

def tomin(s):
    return int(s[:2], 10) * 60 + int(s[-2:], 10)

def foo(idx, ifile, ofile):
    t = int(ifile.readline().strip())
    na, nb = ([int(x) for x in ifile.readline().split()])

    res = []
    for i in range(na):
        line = ifile.readline()
        words = line.split()
        x1 = tomin(words[0])
        x2 = tomin(words[1])
        res.append((x1+0.5, 0, -1))
        res.append((x2+t, 1, 1))
    for i in range(nb):
        line = ifile.readline()
        words = line.split()
        x1 = tomin(words[0])
        x2 = tomin(words[1])
        res.append((x1+0.5, 1, -1))
        res.append((x2+t, 0, 1))

    res.sort()

    data = [0, 0]
    res2 = [0, 0]
    for x in res:
        y = x[1]
        z = x[2]
        data[y] += z
        res2[y] = min(res2[y], data[y])

    ofile.write('Case #%i: %i %i\n' % (idx, -res2[0], -res2[1]))


def main(ifile, ofile):
    x = int(ifile.readline().strip())
    for i in range(x):
        foo(i+1, ifile, ofile)

if __name__ == '__main__':
    main(file(sys.argv[1]), sys.stdout)
