import sys

def case_iterator(path):
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())
        
        for i in range(1, 1 + n):
            yield i, read_case(lines)
    
def line_tostr(line):
    ret = []
    for c in line:
        if c == '.':
            ret.append(None)
        else:
            ret.append(int(c))
    return ret        
       
def read_case(lines):
    n = int(lines.next())
     
    return [line_tostr(lines.next().strip()) for _ in xrange(n)]


def calc_wp(matrix):
    n = len(matrix)
    wp = [None] * n
    for i in xrange(n):
        num_won = sum(j for j in matrix[i] if j is not None)
        total = sum(1 for j in matrix[i] if j is not None)
        wp[i] = float(num_won) / total
        
    return wp

def solve(case):
    matrix = case
    
    wp = calc_wp(matrix)
    
    n = len(matrix)
    owp = [None] * n
    oowp = [None] * n
    rpi = [None] * n
    for i in xrange(n):
        other = matrix[:i] + matrix[i+1:]
        other = [x for x in other if x[i] is not None]
        other = [x[:i] + x[i+1:] for x in other]
        
        other_wp = calc_wp(other)
        owp[i] = float(sum(other_wp)) / len(other_wp)
        
    for i in xrange(n):
        opponents = [j for j in xrange(n) if matrix[j][i] is not None]
        oowp[i] = float(sum([owp[j] for j in opponents])) / len(opponents)
        rpi[i] = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]
        
    return '\n'.join([str(i) for i in rpi])
        
    
        
        
        
        
        
        
        
    
def main():
    try:
        path, = sys.argv[1:]
    except ValueError:
        sys.exit('usage: %s <input file>' % (sys.argv[0],))
    
    for i, case in case_iterator(path):
        print 'Case #%d:' % (i,)
        print '%s' % (solve(case),)
        

if __name__ == '__main__':
    main()
