import sys,collections,itertools

def solve():
    N,A,B,C,D = map(int,input().split())
    chkL = [B+D,B+C,B-C,B-D]
    for i in range(N-2):
        min_v = C*(N-2-i)-D*i+A
        max_v = D*(N-2-i)-C*i+A
        for v in chkL:
            if (min_v <= v and v <= max_v):
                print("YES")
                return
    print("NO")
    
solve()