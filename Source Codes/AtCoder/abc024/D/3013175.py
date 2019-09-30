A = int(input())
B = int(input())
C = int(input())

MOD = 10**9+7

def bit(x):
    res = []
    while x > 0:
        res.append(x%2)
        x //= 2
    res.reverse()
    return res

p = bit(MOD-2)




def inv(x):
    res = 1
    for i in p:
        res = res*res%MOD * x**i%MOD
    return res

c = (B*C-A*B)%MOD*inv((A*(B+C)-B*C))%MOD
r = (B*C-A*C)%MOD*inv((A*(B+C)-B*C))%MOD
print(r, c)