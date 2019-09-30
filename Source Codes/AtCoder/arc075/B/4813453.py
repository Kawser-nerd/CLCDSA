a,b,c = map(int, input().split())
l = [int(input()) for _ in range(a)]
flag = True
l = sorted(l)
max_T = 10**18
def ok(k):
    s = k
    for i in l:
        hp = i - c * k
        if hp > 0:
            s -= -(-hp // (b - c))
        if s < 0:
            return False
    return True
def binary_search(l,r):
    mid = (l + r) // 2
    if l == r:
        return l
    elif ok(mid):
        return binary_search(l,mid)
    else:
        if mid == l:
            mid += 1
            
        return binary_search(mid,r)
ans = binary_search(0,max_T)
print(ans)