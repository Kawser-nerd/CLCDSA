N,M = list(map(int,input().split()))

P = 10**9+7
def get_soinsu(M):
    for i in range(2,1+int(M**0.5)):
        if M%i == 0:
            return [i] + get_soinsu(M//i)
    else:
        return [M]

soinsu = {}
for n in get_soinsu(M):
    soinsu[n] = 1 + soinsu.get(n,0)

def combi(n,r):
    tmp1,tmp2 = (1,1)
    for i in range(n-r+1,n+1):
        tmp1 *= i
    for i in range(2,r+1):
        tmp2 *= i
    return (tmp1//tmp2)%P

out = 1
soinsu.pop(1,None)
for n in soinsu.values():
    out *= combi(N-1+n,n)
    out %= P
print(out)