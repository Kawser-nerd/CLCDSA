import fractions as frac
a, b, c, d, e, f = map(int, input().split())
memo=[[(-1, -1)]*1000 for i in range(10000)]
func = lambda t: frac.Fraction(t[0], t[1]) if t[1]>0 else -10
def dp(s, w):
    if w*e<s or w*100+s>f:
        return (-1, -1)
    m=memo[s][w]
    if m[0]>0:
        return m
    p0=(s,w) 
    p1=dp(s, w+a)
    p2=dp(s, w+b)
    p3=dp(s+c, w)
    p4=dp(s+d, w)
    memo[s][w]=max(p0, p1, p2, p3, p4, key = func) if w>0 else max(p1, p2, key = func)
    return memo[s][w]
    
ans=dp(0,0)
print(ans[0]+ans[1]*100, ans[0])