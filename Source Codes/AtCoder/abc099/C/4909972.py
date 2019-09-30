N = int(input())

memo = {i:i for i in range(6)}
def f(n):
    tmp = memo.get(n,None)
    if tmp != None:
        return tmp
    i,j = 0,0
    a,b = n,n
    while a >= 6:
        i += 1
        a //= 6
    while b >= 9:
        j += 1
        b //= 9
    ret = min(1+f(n-6**i),1+f(n-9**j))
    memo[n] = ret
    return ret

print(f(N))