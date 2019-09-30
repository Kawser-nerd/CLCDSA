import sys
stdin = sys.stdin

sys.setrecursionlimit(10**5)

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

k = ni()

n = 50
a = [i for i in range(n)]

for i in range(n):
    a[i] += (k//n)
    
for i in range(k%n):
    a[i] += n
    for j in range(n):
        if i != j:
            a[j] -= 1
            
print(n)
print(*a)