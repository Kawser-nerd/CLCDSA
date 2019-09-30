input_file = "sample_input.txt"
input_file = "D-small-attempt6.in"
##input_file = "B-small-attempt2.in"
##input_file = "B-large.in"

from multiprocessing import Pool
from itertools import izip

def line(f,_type=str):
    s = [_type(i) for i in f.readline().strip().split()]
    return s

def f_star(args):
    return f(*args)

class Memoize:
    def __init__(self, f):
        self.f = f
        self.memo = {}
    def __call__(self, *args):
        if not args in self.memo:
            self.memo[args] = self.f(*args)
        return self.memo[args]

# solution function
def f(r,c,top):
    'return list of ways to decorate'
    if r == 0:
        return ['']
    if r < 0:
        return []
    ways = []
    if top == 0:
        for i in f(r-2,c,3):
            ways.append('33'+i)
        for i in f(r-1,c,2):
            ways.append('2'+i)
        if c % 4 == 0:
            for i in f(r-3,c,2):
                ways.append('212'+i)
        if c % 3 == 0:
            for i in f(r-2,c,2):
                ways.append('42'+i)
        if c % 6 == 0:
            for i in f(r-2,c,2):
                ways.append('52'+i)
    if top == 2:
        for i in f(r-2,c,3):
            ways.append('33'+i)
    if top == 3:
        for i in f(r-1,c,2):
            ways.append('2'+i)
        if c % 4 == 0:
            for i in f(r-3,c,2):
                ways.append('212'+i)
        if c % 3 == 0:
            for i in f(r-2,c,2):
                ways.append('42'+i)
        if c % 6 == 0:
            for i in f(r-2,c,2):
                ways.append('52'+i)
    return ways

f = Memoize(f)

def count(way):
    q = way.count('1') #4-cycle
    w = way.count('4') #3-cycle
    e = way.count('5') #6-cycle
    if q and w and e:
        c = 6
    elif q and w:
        c = 1
    elif q and e:
        c = 2
    elif w and e:
        c = 3
    else:
        c = 1
    if q > 0:
        c *= pow(4, q - 1, 1000000007)
    if w > 0:
        c *= pow(3, w - 1, 1000000007)
    if e > 0:
        c *= pow(6, e - 1, 1000000007)
    return c

    

if __name__ == "__main__":
    # read inputs
    with open(input_file) as fin:
        T = line(fin,int)[0]
        r = []
        c = []
        for case in range(1,T+1):
            ri,ci = line(fin,int)
            r.append(ri)
            c.append(ci)
        args = zip(r,c)

    answers = []
    for i in range(T):
        ways = f(r[i],c[i],0)
        print r[i],c[i],ways
        answers.append(sum(count(way) for way in ways) % 1000000007)
        
##    # calculate answers
##    pool = Pool()
##    answers = pool.map(f_star,args)

    # print answers
    with open('output_mp.txt','w') as fout:
        for i in range(len(answers)):
            case = i + 1
            answer = answers[i]
            s = "Case #%d: %d\n" % (case, answer)   # change answer format if necessary
            print s,
            fout.write(s)
