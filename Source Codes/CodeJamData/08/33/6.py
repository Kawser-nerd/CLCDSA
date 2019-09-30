import sys

FILE_NAME = 'C-small-attempt0'
INPUT_FILE = FILE_NAME + '.in'
OUTPUT_FILE = FILE_NAME + '.out'

def process(case, n, m, X, Y, Z, B):
    A = [0] * n
    S = [0] * n
    
    for i in range(n):
        A[i] = int(B[i % m])
        B[i % m] = (X * B[i % m] + Y * (i + 1)) % Z
        
    for i in range(n):
        S[i] = 1
        for j in range(i):
            if A[j] < A[i]:
                S[i] = S[i] + S[j]
                
    print 'Case #%d: %d' % (case, sum(S) % 1000000007)
    
def main():
    fp_in = open(INPUT_FILE, 'r')
    fp_out = open(OUTPUT_FILE, 'w')
    
    sys.stdin = fp_in
    sys.stdout = fp_out

    num_cases = int(input())
    
    for case in range(1, num_cases + 1):
        n, m, X, Y, Z = map(int, raw_input().split())
        B = [0] * m
        for i in range(m):
            B[i] = input()
        process(case, n, m, X, Y, Z, B)
        
    fp_in.close()
    fp_out.close()

if __name__ == '__main__':
    main()