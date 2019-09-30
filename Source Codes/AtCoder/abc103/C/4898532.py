N = int(input())
a_list = [int(i) for i in input().split()]

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)

def lcm(a,b):
    return (a*b) // gcd(a,b)

s = a_list[0]
for i in range(1,N):
    s = lcm(s, a_list[i])

def f(m):
    c = 0
    for a in a_list:
        c += m % a
    return c
print(f(s-1))