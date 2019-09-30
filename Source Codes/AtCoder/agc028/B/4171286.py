def remov(n,a):

    mod=10**9+7

    k=[1]*(n+1)
    gk=k[:]
    kb1=k[:]

    for i in range(1,n+1):
        k[i]=k[i-1]*i%mod

    gk[n]=pow(k[n],mod-2,mod)
    for i in range(n,0,-1):
        gk[i-1]=gk[i]*i%mod

    for i in range(1,n+1):
        kb1[i]=gk[i]*k[i-1]%mod

    kerui=[0]*(n+1)
    for i in range(1,n+1):
        kerui[i]=(kerui[i-1]+kb1[i])%mod

    ans=0
    for i in range(n):
        ans+=a[i]*(kerui[i+1]+kerui[n-i]-1)%mod
        ans%=mod
    ans*=k[n]

    return ans%mod

print(remov(int(input()),[int(i) for i in input().split()]))