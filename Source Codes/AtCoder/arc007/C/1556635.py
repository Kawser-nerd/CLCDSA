S = input()
N = len(S)
PTN = int(S.replace('o','1').replace('x','0'), 2)

def rotate_r(n,b):
    return (n >> b) | ((n << (N-b)) & (2**N - 1))

def solve():
    OK = 2**N - 1
    set1 = set()
    set1.add(PTN)
    for n in range(1,N+1):
        set2 = set()
        for ptn in set1:
            if ptn == OK: return n
            for i in range(1,N):
                newptn = ptn | rotate_r(PTN, i)
                set2.add(newptn)
        set1 = set2

print(solve())