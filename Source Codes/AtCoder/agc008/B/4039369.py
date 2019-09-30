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

n,k = li()
a = list(li())

acc_all = [0]
acc_pos = [0]

for ai in a:
    if ai > 0:
        acc_all.append(acc_all[-1] + ai)
        acc_pos.append(acc_pos[-1] + ai)
    else:
        acc_all.append(acc_all[-1] + ai)
        acc_pos.append(acc_pos[-1])

ans = 0    
for st in range(n-k+1):
    black = (acc_all[st+k] - acc_all[st])\
            + (acc_pos[n] - acc_pos[st+k])\
            + (acc_pos[st] - acc_pos[0])
    white = (acc_pos[n] - acc_pos[st+k])\
            + (acc_pos[st] - acc_pos[0])

    ans = max(ans, black, white)
    
print(ans)