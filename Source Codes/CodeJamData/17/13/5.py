
# do buffs, then do attacks
# call these attacks "hits"
# x buffs, y attacks =>  (ad+x*b)*y damage
# hits = min(x + round up(hk/(ad+x*b)))
# hits = min(x + 1 + (hk-1)/(ad+x*b)))

import sys
sys.stdin=open("data.txt")
sys.stdout=open("out.txt","w")
input=sys.stdin.readline

for cnum in range(int(input())):
    hd,ad,hk,ak,b,d=map(int,input().split())
    # do corner cases
    """
    ans=-2
    if hk<=ad: ans=1
    elif ak-d>=hd: ans=-1
    if ans!=-2:
        if ans==-1: print("Case #%d: IMPOSSIBLE"%(cnum+1))
        else: print("Case #%d: %d"%(cnum+1,ans))
        continue
    """
    # get hits
    hits=(hk-1)//(ad)
    if b:
        for x in range(0,hits+1):
            hits=min(hits,x+(hk-1)//(ad+x*b))
    # do debuff stuff
    ans=10**4
    for dcount in range(0,ak+1 if d>0 else 1):
        tick=0
        hp=hd
        ak2=ak
        while dcount>0 and tick<10**4:
            if hp>ak2-d:
                ak2-=d
                dcount-=1
                hp-=ak2
            else:
                hp=hd-ak2
            tick+=1
        hitsleft=hits
        while hitsleft>0 and tick<10**4:
            if hp>ak2:
                hitsleft-=1
                hp-=ak2
            else:
                hp=hd-ak2
            tick+=1
        ans=min(ans,tick)
        if ak2<=0: break
    if ans==10**4: print("Case #%d: IMPOSSIBLE"%(cnum+1))
    else: print("Case #%d: %d"%(cnum+1,ans+1))
