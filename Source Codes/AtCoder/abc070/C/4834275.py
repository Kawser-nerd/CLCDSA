N = int(input())
R = list(int(input())for _ in range(N))
def gcd(a,b):
        if a < b:
            c = b
            b = a
            a = c
        while b != 0:
            c = a % b
            a = b
            b = c
        return a
def lcm(a,b):
    c = a*b//gcd(a,b)
    return c
p = R[0]
for i in range(N):
    p = lcm(p,R[i])
print(p)