n=int(input())
s=input()
t=input()
a={}
for c,d in zip(s,t):
    if c not in a:
        a[c]=set()
    a[c].add(d)
    if d not in a:
        a[d]=set()
    a[d].add(c)
def f(x):
    if x in a:
        l=a.pop(x)
        for t in l:
            f(t)
for i in range(0,10):
    f(str(i))
c=1
while a:
    h=list(a.keys())[0]
    c*=(10-(h==s[0] or h==t[0]))
    f(h)
print(c)