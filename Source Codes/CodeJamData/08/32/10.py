import sys
import psyco

psyco.full()

FILE_NAME = 'B-small-attempt2'
INPUT_FILE = FILE_NAME + '.in'
OUTPUT_FILE = FILE_NAME + '.out'

def is_ugly(n):
    if n % 2 == 0:
        return True
    if n % 3 == 0:
        return True
    if n % 5 == 0:
        return True
    if n % 7 == 0:
        return True
    return False

count = 0
    
def recur(idx, sol, str):
    global count
    
    n = len(str) - 1
    digit = map(int, str)
    
    for k in range(3 ** (len(str) - 1)):
        for j in range(n):
            sol[j] = k % 3
            k = k / 3
        
        result = 0
        num = digit[0]
        last_op = 0
        for i in range(n):
            if sol[i] != 0:
                if last_op == 0:
                    result = num
                elif last_op == 1:
                    result = result + num
                elif last_op == 2:
                    result = result - num
                last_op = sol[i]
                num = digit[i + 1]
            else:
                num = num * 10 + digit[i + 1]

        if last_op == 0:
            result = num
        elif last_op == 1:
            result = result + num
        elif last_op == 2:
            result = result - num
        
        if result % 2 == 0 or result % 3 == 0 or result % 5 == 0 or result % 7 == 0:
            count = count + 1
    
def process(case, str):
    global count
    count = 0
    
    sol = [0] * (len(str) - 1)
    recur(0, sol, str)
    
    print 'Case #%d: %d' % (case, count)
    
def main():
    fp_in = open(INPUT_FILE, 'r')
    fp_out = open(OUTPUT_FILE, 'w')
    
    sys.stdin = fp_in
    #sys.stdout = fp_out

    num_cases = int(input())
    
    for case in range(1, num_cases + 1):
        str = raw_input().strip()
        process(case, str)
        
    fp_in.close()
    fp_out.close()

if __name__ == '__main__':
    main()