import sys

FILE_NAME = 'A-large'
INPUT_FILE = FILE_NAME + '.in'
OUTPUT_FILE = FILE_NAME + '.out'

OP_OR = 0
OP_AND = 1

INF = 10000000

def recur(m, g, c, a, i, desired):
    if a[i] == desired:
        return 0
   
    if i * 2 > m:
        return INF
    
    no_change = 0
    change = 0
    
    if g[i] == OP_OR:
        if desired == 0:
            left_ret = recur(m, g, c, a, i * 2, 0)
            right_ret = recur(m, g, c, a, i * 2 + 1, 0)
            no_change = left_ret + right_ret
            change = min(left_ret, right_ret) + 1
        else:
            left_ret = recur(m, g, c, a, i * 2, 1)
            right_ret = recur(m, g, c, a, i * 2 + 1, 1)
            no_change = min(left_ret, right_ret)
            change = left_ret + right_ret + 1
    elif g[i] == OP_AND:
        if desired == 0:
            left_ret = recur(m, g, c, a, i * 2, 0)
            right_ret = recur(m, g, c, a, i * 2 + 1, 0)
            no_change = min(left_ret, right_ret)
            change = min(left_ret, right_ret) + 1
        else:
            left_ret = recur(m, g, c, a, i * 2, 1)
            right_ret = recur(m, g, c, a, i * 2 + 1, 1)
            no_change = left_ret + right_ret
            change = min(left_ret, right_ret) + 1
    else:
        assert False

    if c[i] == 0:
        change = INF
    
    #print i, desired, no_change, change
    return min(no_change, change)
    
def process(case, m, v, g, c, a):
    st_leaf = (m - 1) / 2 + 1
    num_leaf = (m + 1) / 2
    
    for i in xrange(st_leaf - 1, 0, -1):
        left = a[i * 2]
        right = a[i * 2 + 1]
        if g[i] == OP_OR:
            a[i] = left | right
        else:
            a[i] = left & right
    
    ret = recur(m, g, c, a, 1, v)
    if ret >= INF:
        print 'Case #%d: IMPOSSIBLE' % (case)
    else:
        print 'Case #%d: %d' % (case, ret)
    
def main():
    fp_in = open(INPUT_FILE, 'r')
    fp_out = open(OUTPUT_FILE, 'w')
    
    sys.stdin = fp_in
    sys.stdout = fp_out

    num_cases = int(input())
    
    for case in range(1, num_cases + 1):
        m, v = map(int, raw_input().split())
        g = [0] * (m + 1)     # 0 for or, 1 for and
        c = [0] * (m + 1)
        a = [0] * (m + 1)
        
        for i in xrange((m - 1) / 2):
            g[i + 1], c[i + 1] = map(int, raw_input().split())
        
        for i in xrange((m + 1) / 2):
            a[(m - 1) / 2 + 1 + i] = input()
            
        process(case, m, v, g, c, a)
        
    fp_in.close()
    fp_out.close()

if __name__ == '__main__':
    main()