
def read_ints():
    return map(int, raw_input().split(" "))

def test(cnt, n, m, splits):
    def gen_colors(dep, colors):
        if dep == n:
            cnt_split = 0
            for sp in splits:
                cc = []
                for s in sp:                
                    c = colors[s - 1]
                    if c not in cc:
                        cc += [c]
                if len(cc) == cnt:
                    cnt_split += 1
            if cnt_split == len(splits):
                scheme = [x for x in colors]
                return True, scheme
        else:
            for c in range(1, cnt+1):
                colors[dep] = c
                flag, sch = gen_colors(dep+1, colors)
                if flag == True:
                    return flag, sch
        return False, []
   
    colors = [0] * n
    return gen_colors(0, colors)

def solve(n, m, splits):
    max_possi = min([len(x) for x in splits])
    #print max_possi
    lst = []
    best = 0
    for cnt in range(1, max_possi + 1):
        ok, ans = test(cnt, n, m, splits)
        #print cnt, ok, ans
        if ok is False: 
            break;
        else:
            lst = ans
            best = cnt
    print best
    print " ".join([str(x) for x in lst])

def find_split(splits, a, b):
    for s in splits:
        if a in s and b in s:
            return s

def get_split(n, m, st, ed):
    splits = [[x+1 for x in range(n)]]
    for i in range(m):
        a = st[i]
        b = ed[i]
        s = find_split(splits, a, b)
        if a > b:
            a, b = b, a
        splits.remove(s)
        si = s[s.index(a):s.index(b) + 1]
        sj = s[0:s.index(a) + 1] + s[s.index(b):]
        splits += [si]
        splits += [sj]
        #print splits
    return splits

#a = [0, 1, 2, 3, 4]


def main():
    T, = read_ints()
    for cas in xrange(T):
        N, M = read_ints()
        a = read_ints()
        b = read_ints()
        
        splits = get_split(N, M, a, b)
        print "Case #%d: " % (cas+1),
        solve(N, M, splits)

if __name__ == '__main__':
    main()
