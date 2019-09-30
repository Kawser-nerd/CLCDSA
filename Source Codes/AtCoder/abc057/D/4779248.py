N,A,B=list(map(int, input().strip().split()))
v=sorted(list(map(int, input().strip().split())))[::-1]

def frac(n):
    ret=1
    for i in range(2,n+1):
        ret*=i
    return ret
def combi(n,a):
    return frac(n)//frac(a)//frac(n-a)

sm=sum(v[:A])
ave=sm/A
ans=0

minA = v[A-1]
ct_mA = v[:A].count(minA)
nmA = v.count(minA)

if ave == minA:
    i=0
    while A+i <=B and i<=nmA-ct_mA:
        ans+=combi(nmA,i+A)
        i+=1
else:
    ans = combi(nmA,ct_mA)
print(ave)
print(ans)