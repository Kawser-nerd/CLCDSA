import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        s = list(f.readline().strip())

        first = 0
        for i in xrange(len(s) - 1):
            if s[i] < s[i+1]:
                first = i+1
            if s[i] > s[i+1]:
                s[first] = chr(ord(s[first]) - 1)
                for j in xrange(first + 1, len(s)):
                    s[j] = '9'
                break

        print "Case #%d: %s" % (_T + 1, int(''.join(s)))
