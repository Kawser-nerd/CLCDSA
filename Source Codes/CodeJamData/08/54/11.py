import sys

FILE_NAME = 'D-small-attempt1'
INPUT_FILE = FILE_NAME + '.in'
OUTPUT_FILE = FILE_NAME + '.out'

def process(case, H, W, R, r, c):
    
    def recur(x, y):
        if x < 1 or y < 1:
            return 0
        
        if x == 1 and y == 1:
            return 1
        
        if (x, y) in cache:
            return cache[(x, y)]
        
        for i in xrange(R):
            if x == r[i] and y == c[i]:
                return 0
             
        ret = recur(x - 1, y - 2) + recur(x - 2, y - 1)
        cache[(x, y)] = ret
        return ret
    
    print 'Case #%d:' % case,

    cache = {}
    print '%d' % (recur(H, W) % 10007)
    
def main():
    class tee:
        def __init__(self, *fileobjects):
            self.fileobjects=fileobjects
        def write(self, string):
            for fileobject in self.fileobjects:
                fileobject.write(string)

    fp_in = open(INPUT_FILE, 'r')
    fp_out = open(OUTPUT_FILE, 'w')
    
    sys.stdin = fp_in
    sys.stdout = tee(sys.stdout, fp_out)

    num_cases = int(input())
    
    for case in range(1, num_cases + 1):
        H, W, R = map(int, raw_input().split())
        r = []
        c = []
        for i in xrange(R):
            t1, t2 = map(int, raw_input().split())
            r.append(t1)
            c.append(t2)
            
        process(case, H, W, R, r, c)
        
    fp_in.close()
    fp_out.close()

if __name__ == '__main__':
    import psyco
    psyco.full()
    main()