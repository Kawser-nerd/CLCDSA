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

# i-bit??j-bit???????
def swap_digit(num:int, i:int, j:int):
    if num & (1<<i) and not (num & (1<<j)):
        return num - (1<<i) + (1<<j)
    
    elif not (num & (1<<i)) and num & (1<<j):
        return num + (1<<i) - (1<<j)
    
    else:
        return num
    

# 2????bit??????????
def different_digit(n: int, a: int, b: int):
    ret = n-1

    for digit in range(n-1, -1, -1):
        if (a^b) & (1<<digit):
            return digit
        
    return ret

# ??bit?????????
def rec(n: int, a: int, b: int):
    if n == 1:
        return [a,b]
    
    dd = different_digit(n,a,b)
    
    a = swap_digit(a, n-1, dd)
    b = swap_digit(b, n-1, dd)
    na = a & ((1<<(n-1)) - 1)
    nb = b & ((1<<(n-1)) - 1)
    
        
    first = rec(n-1, na, na^1)
    latte = rec(n-1, na^1, nb)

    if a & (1<<(n-1)):
        ret = list(map(lambda x: x + (1<<(n-1)), first)) + latte
    else:
        ret = first + list(map(lambda x: x + (1<<(n-1)), latte))

    return [swap_digit(reti, n-1, dd) for reti in ret]


n,a,b = li()
if bin(a).count('1') % 2 == bin(b).count('1') % 2:
    print("NO")
    
else:
    print("YES")
    print(*rec(n,a,b))