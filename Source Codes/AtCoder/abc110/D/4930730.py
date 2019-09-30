from math import factorial, sqrt
N,M=map(int,input().split())
prms={}
tmp=M
for i in range(2, int(sqrt(M))+2):
    while not tmp%i:
        if not i in prms:
            prms[i]=1
        else:
            prms[i]+=1
        tmp //= i
if tmp != 1:
    prms[tmp] = 1

# print(prms)

res=1
def cmb(a,b):
    res=1
    if a - b < b:
        b = a-b
    for i in range(b):
        res *= (a-i)
        res //= (i+1)
    return res

for p, cnt in prms.items():
    res *= cmb(cnt+N-1, cnt)
    res %= 1000000007

print(res % 1000000007)