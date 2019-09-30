import sys
import psyco

psyco.full()

FILE_NAME = 'D-small-attempt0'
INPUT_FILE = FILE_NAME + '.in'
OUTPUT_FILE = FILE_NAME + '.out'

def rle(s):
    ret = 0
    last = '!'
    for c in s:
        if c != last:
            ret += 1
            last = c
    return ret

def recur(depth, k, sol, s):
    if depth >= k:
        new_s = ['_'] * len(s)
        for i in xrange(len(s)):
            new_s[i] = s[i - (i % k) + sol[i % k]]
        return rle(new_s)
    else:
        ret = 999999999
        for i in xrange(k):
            if i in sol[:depth]:
                continue
            sol[depth] = i
            ret = min(ret, recur(depth + 1, k, sol, s))
        return ret
            
def process(case, k, s):
    print 'Case #%d: %d' % (case, recur(0, k, [0] * k, s))
    
def main():
    fp_in = open(INPUT_FILE, 'r')
    fp_out = open(OUTPUT_FILE, 'w')
    
    sys.stdin = fp_in
    #sys.stdout = fp_out

    num_cases = int(input())
    
    for case in range(1, num_cases + 1):
        k = int(input())
        s = raw_input().strip()
        process(case, k, s)
        
    fp_in.close()
    fp_out.close()

if __name__ == '__main__':
    main()