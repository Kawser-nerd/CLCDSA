def g(a, b):
    if a%b == 0: return b
    return g(b, a%b)

def f(a, b, c, d):
    yes = "Yes"
    no  = "No"
    if a<b or d<b: return no
    if c>=b or a<=c: return yes
    if (a-c)%b>0 and (a-c)%b<b-c: return no
    e = d%b
    if e==0 or b-c==1: return yes
    if e==1: return no
    h = g(b, e)
    if h<b-c: return no
    if (a-c)%h>0 and (a-c)%h<b-c: return no
    return yes

t = int(input())
for i in range(t):
    a, b, c, d = map(int, input().split())
    ans = f(a, b, c, d)
    print(ans)