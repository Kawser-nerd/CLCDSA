N,M = (list(map(int,input().split())))
S = input()
T = input()

def gcd(x,y):
    x,y = min(x,y),max(x,y)
    if y%x == 0:
        return x
    return gcd(x,y%x)
    
def main():
    if S[0] != T[0]:
        return -1
    g = gcd(N,M)
    n = N//g
    m = M//g
    for i in range(g):
        if S[n*i] != T[m*i]:
            return -1
    return N*M//g

print(main())