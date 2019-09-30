n = int(input())

def s(a):
    ret = 0
    for i in range(len(str(a))):
        ret += int(str(a)[i])
    return ret

ans = 10**10
for i in range(1,n):
    a = i
    b = n - a
    ans = min(ans , s(a)+s(b))
print(ans)