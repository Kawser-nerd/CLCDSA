import sys
import pprint
import random

FILE_NAME = 'C-small-attempt1'
INPUT_FILE = FILE_NAME + '.in'
OUTPUT_FILE = FILE_NAME + '.out'

def process(case, M, N, broken):
    print 'Case #%d:' % case,
    
    def feasible(i, j):
        if broken[i][j] == 1:
            return False
        
        if i > 0:
            if j > 0 and sol[i - 1][j - 1] == 1:
                return False
            if j < N -1 and sol[i - 1][j + 1] == 1:
                return False
            
        if j > 0 and sol[i][j - 1] == 1:
            return False
        if j < N -1 and sol[i][j + 1] == 1:
            return False
        
        if i < M - 1:
            if j > 0 and sol[i + 1][j - 1] == 1:
                return False
            if j < N -1 and sol[i + 1][j + 1] == 1:
                return False            
        
        return True
   
    def greedy():
        ret = 0
    
        order = []
        for i in xrange(M):
            for j in xrange(N):
                order.append((i, j))
        random.shuffle(order)

        for i, j in order:
            if sol[i][j] == 0 and feasible(i, j):
                sol[i][j] = 1
                ret += 1
                    
        return ret
    
    max_value = 0
    for iter in xrange(3000):
        sol = [[0] * N for i in xrange(M)]
        total = 0
        for k in xrange(M * N / 20):
            i = random.randint(0, M - 1)
            j = random.randint(0, N - 1)
            if sol[i][j] == 0 and feasible(i, j):
                total += 1
                sol[i][j] = 1                 
        total += greedy()
        #if total > max_value:
        #    pprint.pprint(sol)
        max_value = max(max_value, total) 
    
    print max_value
    
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
        M, N, = map(int, raw_input().split())
        broken = [[0] * N for i in xrange(M)]
        for i in xrange(M):
            line = raw_input()
            for j in xrange(N):
                if line[j] == 'x':
                    broken[i][j] = 1
        process(case, M, N, broken)
        
    fp_in.close()
    fp_out.close()

if __name__ == '__main__':
    import psyco
    psyco.full()
    main()