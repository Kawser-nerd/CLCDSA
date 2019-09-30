def calc(r, k, size):
    n = len(size)
    history = {}
    money = []
    pos = 0
    for round in xrange(r):
        if pos in history:
            repeat = money[history[pos]:]
            l = len(repeat)
            remain = r - round
            final = (remain / l) * sum(repeat) + sum(repeat[:remain%l]) + sum(money)
            return final
        history[pos] = len(money)

        m = 0
        start = pos
        while True:
            if m + size[pos] > k:
                break
            m += size[pos]
            pos = (pos + 1) % n
            if pos == start:
                break
        money.append(m)
    return sum(money)
    

def work(name):
    f = open(name + ".in")
    out = open(name + ".out", 'w')
    case_max = int(f.readline())
    for caseno in xrange(1, case_max + 1):
        out.write("Case #%d: " % caseno)
        r, k, n = map(int, f.readline().split())
        size = map(int, f.readline().split())
        out.write("%d\n" % calc(r, k, size))        
    f.close()
    out.close()

if __name__ == "__main__":
    #work("3")
    #work("C-small-attempt0")
    work("C-large")
    
