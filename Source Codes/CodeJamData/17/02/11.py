import sys
sys.stdin=open("BL.in","r")
sys.stdout=open("BL.out","w")
t=input()

def solve(s):
    l=len(s)
    w=s[0]*l
    if w>s:
        ans=""
        if s[0]!='1': ans+=chr(ord(s[0])-1)
        ans+="9"*(l-1)
        return ans
    for i in range(l):
        w=s[0:i]+s[i]*(l-i)
        if w>s: return s[0:i]+chr(ord(s[i])-1)+"9"*(l-i-1)
    return s
for tt in range(1,t+1):
    s=raw_input()
    ans=solve(s)
    print "Case #{0}: {1}".format(tt,ans)

