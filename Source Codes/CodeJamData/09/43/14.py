import sys


class Chart(object):
    def __init__(self, nr):
        self.nr = nr
        self.enemy = []

    def is_enemy(self, ch):
        return ch.nr in self.enemy

    def __unicode__(self):
        return self.nr

def crossing( taba, tabb ):
    if taba[0] > tabb[0]:
        taba, tabb = tabb, taba

    for x in range(len(taba)):
        if taba[x] >= tabb[x]:
            return True
    return False

def run(ch):
    if len(ch) == 0:
        return 0

    if len(ch) == 1:
        return 1

    ret = [ch[0]]

    def xx(start):
        #print 'start: %d' % start
        result = 999
        found = 0
        for x in range(start, len(ch)):
            enemy = False
            for c in ret:
                if c.is_enemy(ch[x]):
                    enemy = True
                    break

            if not enemy:
                ret.append( ch[x] )
                result = min( xx(x+1), result)
                del ret[-1]
                found += 1
                if found == 4:
                    break

        # nothing found
        if not found:
            #print [a.nr for a in ret]
            result = min( run( [c for c in ch if c not in ret] ), result)
            #print result
        return result

    return xx(1) + 1

def main():
    def next_line():
        return sys.stdin.readline()
    
    t = int(next_line())
    for X in range(1,t+1):
        n,k = next_line().split()
        n,k = int(n), int(k)

        tab = []

        for x in range(n):
            line = next_line().split()
            tab.append( [int(i) for i in line] )

        ch = [Chart(i) for i in range(n)]

        ch = sorted(ch, key=lambda x:len(x.enemy))

        for x in range(n):
            for y in range(x+1,n):
                if crossing( tab[x], tab[y]):
                    ch[x].enemy.append(y)
                    ch[y].enemy.append(x)


        print "Case #%d: %d" % (X, run(ch))

main()
