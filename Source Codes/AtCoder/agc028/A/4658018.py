N, M = map(int, input().split())
S = input()
T = input()
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
def lcm(a, b):
    return a * b // gcd(a, b)
l = lcm(N, M) 
print(lcm(N, M)) if all(S[(l//M) * i] == T[(l//N) * i] for i in range(gcd(N, M))) else print(-1)