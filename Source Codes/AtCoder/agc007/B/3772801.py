import sys,collections,itertools

def solve():
    N = int(input())
    P = list(map(int,input().split()))
    L = [1 + N*i for i in range(N)]
    Lr = L[::-1]
    for i,v in enumerate(P):
        L[v-1] += i
    print(*L)
    print(*Lr)
        
solve()