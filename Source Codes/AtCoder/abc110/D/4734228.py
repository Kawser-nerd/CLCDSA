n,m=map(int,input().split())

def prime(n):#???????????1????????0
    for i in range(2,n):
        if n%i==0:
            return 0
    return 1

#def prime_l(n):
#    for i in range(2,n+1):
#        if prime(i)==1:
#            yield i
#def prime_l(n):#n?????????
#    l=[1 for i in range(2,n+1)]#2??n??n-1? ????-2
#    for i in range(n-1):#0??n-2 ????=???
#        if prime(i+2):
#            for j in range(2,n//(i+2)+1):#????0????
#                l[(i+2)*j-2]=0
#    return l

def prime_l(n):
    l=[1 for i in range(2,n+1)]#2??n ????-2
    #sq_n=n**(1/2)
    for i in range(n-1):
        if l[i]==1:
            for j in range(2*(i+2),n+1,i+2):
                l[j-2]=0
    l1=[]
    for i in range(n-1):
        if l[i]==1:
            l1.append(i+2)
    return l1


def modpow(a,n,p):#a^n mod p
    res=1
    while n>0:
        if n&1:#?????????????????
            res=res*a%p
        a=a*a%p
        n>>=1
        #????????_2?????n????????????????_???????
    return res

if m==1:
    print(1)
else:
    #l=[i+2 for i in prime_l(int(1e9))]
    #l=prime_l(int(m**(1/2))) if m>=4 else prime_l(m)
    l=prime_l(int(m**(1/2)))#??????????1?????????????
    #ll=next(l)
    i=0
    d={}
    while m!=1 and i!=len(l):
        if m%(l[i])==0:
            d[l[i]]=1
            m/=l[i]
            while m%(l[i])==0:
                d[l[i]]+=1
                m/=l[i]
        #ll=next(l)
        i+=1
        #while l[i]==0:
        #    i+=1
    if m!=1:
        d[m]=1
    #s_k=0
    #for i in d.values():
    #    s_k+=i
    #print(d.values())
    mod=int(1e9+7)
    n_fac=1
    fac_l=[1]#0!
    d_max=max(d.values())
    #for i in range(n+d_max-1):# 1!,2!,,,,(n+d_max-1)!
    #    n_fac*=i+1
    for i in range(n+d_max-1):# 0!,1!,2!,,,,(n+d_max-1)!
        n_fac*=i+1
        n_fac=n_fac%mod
        fac_l.append(n_fac)

    fac_1_l=[]
    for i in range(n+d_max):
        fac_1_l.append(modpow(fac_l[i],mod-2,mod))
    w=1
    for dv in d.values():
        w*=fac_l[n+dv-1]
        w=w%mod
        #n_n_fac=fac_l[n-dv]
        #div=int((fac_l[n-1-1]*fac_l[dv-1])%(1e9+7))
        #print(div)
        #if div>w:
        #    w+=1e9+7
        #w=int(w/div)
        w=w*fac_1_l[n-1]%mod
        w=w*fac_1_l[dv]%mod
    print(w)