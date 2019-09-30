#inputFileName = "test.in"
#inputFileName = "B-small-attempt0.in"
#inputFileName = "B-small-attempt1.in"
#inputFileName = "B-small-attempt2.in"
#inputFileName = "B-small-attempt3.in"
#inputFileName = "B-small-attempt4.in"
inputFileName = "B-large.in"
outputFileName = inputFileName[:-3] + ".out"

def calcN(X, Y):
    s = abs(X) + abs(Y)
    n = int((2 * s + 0.25) ** 0.5 - 0.5)
    s2 = 0
    while True:
        s2 = n * (n + 1) / 2
        if (s2 >= s) and ((s2 - s) % 2 == 0):
            break
        n += 1
    print "X={0}, Y={1}, s={2}, n={3}, s2={4}".format(X, Y, s, n, s2)
    return (n, s2)

# Y0 = 0!!!
def calcSingleTest2(X0, Y0):
    X = abs(X0)
    Y = abs(Y0)
    s = abs(X) + abs(Y)
    n, s2 = calcN(X, Y)
    d = (s2 - s) / 2
    print "X0={0}, Y0={1}, s={2}, n={3}, s2={4}, d={5}".format(X0, Y0, s, n, s2, d)
    d1 = 0
    d2 = 0
    if d > n:
        d1 = d / 2 + 1
        d2 = d - d1
        print "d = {0}, d1={1}, d2={2}".format(d, d1, d2)
    x_list = []
    y_list = []
    xs = X
    #ys = Y
    ys = Y + d

    for i in xrange(n, 0, -1):
        if i == d or i == d1 or i == d2:
            y_list.append(-i)
            continue
        if xs >= i:
            xs -= i
            x_list.append(i)
        else:
            y_list.append(i)
            ys -= i
    pass
    #    for i in xrange(n, 0, -1):
    #        if i == d:
    #            if xs == i:
    #                d = -1
    #                d1 = i - 1
    #                d2 = 1
    #            else:
    #                y_list.append(-i)
    #                continue
    #        if i == d1 or i == d2:
    #            y_list.append(-i)
    #            continue
    #        if xs >= i:
    #            xs -= i
    #            x_list.append(i)
    #        else:
    #            y_list.append(i)
    #            ys -= i

    #    for i in xrange(n, 0, -1):
    #        if i == d or i == d1 or i == d2:
    #            y_list.append(-i)
    #            continue
    #        if xs >= i:
    #            xs -= i
    #            x_list.append(i)
    #        else:
    #            y_list.append(i)
    #            ys -= i
    #    print "xs={0}, ys={1}".format(xs, ys)
    #    if xs == 1:
    #        for i in xrange(x_list[0], 0, -1):
    #            if i not in x_list:
    #                x_pos = x_list.index(i + 1)
    #                y_pos = y_list.index(i)
    #                print x_list
    #                print y_list
    #                print 'swap {0}: {1} {2}; {3} {4}'.format(i, x_pos, x_list[x_pos], y_pos, y_list[y_pos])
    #                x_list[x_pos] = i
    #                y_list[y_pos] = i + 1
    #                break

    print "xs={0}, ys={1}".format(xs, ys)
    #print x_list
    #print y_list
    if xs != 0:
        print "AAAAAAAAAA xs = " + str(xs)
        raise ValueError("AAAAAAAAAA xs = " + str(xs))
    if ys != 0:
        print "AAAAAAAAAA ys = " + str(ys)
        raise ValueError("AAAAAAAAAA ys = " + str(ys))

    x_list.reverse()
    y_list.reverse()
    #print x_list
    #print y_list

    if X0 < 0:
        x_list = map(lambda x: -x, x_list)
    if Y0 < 0:
        y_list = map(lambda x: -x, y_list)
    print x_list
    print y_list

    return (n, x_list, y_list)


def calcSingleTest(f):
    line = f.readline()
    X0 = int(line.split()[0])
    Y0 = int(line.split()[1])
    X = X0
    Y = Y0
    swap = (Y == 0)
    if swap:
        X, Y = Y, X
    pass
    #n, x_list, y_list = calcSingleTest2(X, Y)
    try:
        n, x_list, y_list = calcSingleTest2(X, Y)
    except ValueError:
        print "BBBBBBBBBB fix error by swap"
        if swap:
            raise ValueError("BBBBBBB already swap")
        swap = True
        X, Y = Y, X
        n, x_list, y_list = calcSingleTest2(X, Y)

    if swap:
        y_list, x_list = x_list, y_list
    res_str = ""
    xt = 0
    yt = 0
    for i in xrange(1, n + 1):
        if i in x_list:
            xt += i
            res_str += 'E'
        elif -i in x_list:
            xt -= i
            res_str += 'W'
        elif i in y_list:
            yt += i
            res_str += 'N'
        elif -i in y_list:
            yt -= i
            res_str += 'S'
        else:
            print "AAAAAAAAAA " + str(i)
            raise ValueError("AAAAAAAAAA " + str(i))
    if xt != X0 or yt != Y0:
        print 'CCC: X={0}, Y={1}, xt={2}, yt={3}'.format(X, Y, xt, yt)
        raise ValueError("CCCCCCC")
    return res_str

with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))




