import sys
stdin = sys.stdin

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

n = ni()
left = []
right = []
for _ in range(n):
    l,r = li()
    left.append(l)
    right.append(r)
    
left.sort(reverse=True)
right.sort(reverse=False)

ans_l = 0
last = 0
for i in range(n):
    if left[i] - last < 0:
        ans_l += abs(last)
        break
    else:
        ans_l += (left[i] - last) 
        last = left[i]
    
    if last - right[i] < 0:
        ans_l += abs(last)
        break
    else:
        ans_l += (last - right[i])
        last = right[i]
    
ans_r = 0
last = 0
for i in range(n):
    if last - right[i] < 0:
        ans_r += abs(last)
        break
    else:
        ans_r += (last - right[i])
        last = right[i]
    
    if left[i] - last < 0:
        ans_r += abs(last)
        break
    else:
        ans_r += (left[i] - last) 
        last = left[i]
    


print(max(ans_l, ans_r))