import sys


def main():
    def next_line():
        return sys.stdin.readline()
    
    t = int(next_line())
    for x in range(1,t+1):
        n = int(next_line())

        tab = [0] * n
        for i in range(n):
            line = next_line()
            for nr,c in enumerate(list(line)):
                if c == '1':
                    tab[i] = nr

        ret = 0
        for i in range(n):
            for j in range(i,n):
                if tab[j] <= i:
                    a = tab[j]
                    del tab[j]
                    tab.insert(i,a)
                    ret += j-i
                    break

        print "Case #%d: %d" % (x, ret)

main()
