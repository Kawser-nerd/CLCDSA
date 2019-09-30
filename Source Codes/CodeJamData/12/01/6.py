import sys

d = {
        'a':'y',
        'o':'e',
        'z':'q',
        ' ':' ',
        'r':'p',
        'l':'m',
        'n':'s',
        'g':'l',
        'u':'j',
        'e':'c',
        'i':'k',
        's':'d',
        'm':'x',
        'p':'v',
        't':'r',
        'd':'i',
        'b':'n',
        'h':'b',
        'w':'t',
        'y':'a',
        'x':'h',
        'f':'w',
        'c':'f',
        'k':'o',
        'j':'u',
        'v':'g',
        'q':'z',
        '\n':'\n',
        }

r = dict((v,k) for (k,v) in d.items())

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    f.readline()
    i = 1
    for l in f:
        sys.stdout.write("Case #%d: " % i)
        for c in l:
            # sys.stdout.write(r.get(c, '?'))
            sys.stdout.write(r[c])
        i += 1

