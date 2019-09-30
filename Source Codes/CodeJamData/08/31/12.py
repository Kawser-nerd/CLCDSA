import sys

FILE_NAME = 'A-large'
INPUT_FILE = FILE_NAME + '.in'
OUTPUT_FILE = FILE_NAME + '.out'

def process(case, p, k, l, f):
    slots = [[] for i in range(k)]
    f.sort(reverse = True)
    
    total = 0
    for i, cnt in enumerate(f):
        total = total + cnt * (i / k + 1)

    print 'Case #%d: %d' % (case, total)
    
def main():
    fp_in = open(INPUT_FILE, 'r')
    fp_out = open(OUTPUT_FILE, 'w')
    
    sys.stdin = fp_in
    sys.stdout = fp_out

    num_cases = int(input())
    
    for case in range(1, num_cases + 1):
        p, k, l = map(int, raw_input().split())
        f = map(int, raw_input().split())
        process(case, p, k, l, f)
        
    fp_in.close()
    fp_out.close()

if __name__ == '__main__':
    main()