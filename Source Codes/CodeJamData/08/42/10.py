import sys
import psyco

psyco.full()
FILE_NAME = 'B-small-attempt0'
INPUT_FILE = FILE_NAME + '.in'
OUTPUT_FILE = FILE_NAME + '.out'

def area_mul2(x1, y1, x2, y2, x3, y3):
    return (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2)

def process(case, n, m, a):
    x1 = 0
    y1 = 0
    
    for x2 in xrange(n + 1):
        for y2 in xrange(m + 1):
            for x3 in xrange(n + 1):
                for y3 in xrange(m + 1):
                    if area_mul2(x1, y1, x2, y2, x3, y3) == a:
                        print 'Case #%d: %d %d %d %d %d %d' % (case, x1, y1, x2, y2, x3, y3)
                        return 
    
    print 'Case #%d: IMPOSSIBLE' % case
    
def main():
    fp_in = open(INPUT_FILE, 'r')
    fp_out = open(OUTPUT_FILE, 'w')
    
    sys.stdin = fp_in
    #sys.stdout = fp_out

    num_cases = int(input())
    
    for case in range(1, num_cases + 1):
        n, m, a = map(int, raw_input().split())
        process(case, n, m, a)
        
    fp_in.close()
    fp_out.close()

if __name__ == '__main__':
    main()