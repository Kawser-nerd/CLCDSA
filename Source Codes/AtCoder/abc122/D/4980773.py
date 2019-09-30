n=int(input())
m=[{}for i in range(n+1)]
w=10**9+7
def f(s):
    for i in range(4):
        t=list(s)
        if i>=1:
            t[i-1],t[i]=t[i],t[i-1]
        if "".join(t).count("AGC")>0:
            return False
    return True
def a(p,q):
    if q in m[p]:
        return m[p][q]
    if p==n:
        return 1
    r=0
    for i in "AGCT":
        if f(q+i):
            r=(r+a(p+1,q[1:]+i))%w
    m[p][q]=r
    return r
print(a(0,"WHY"))