n = int(input())
t = [int(input()) for _ in range(n)]
def f(a,b):
    if b==0:
        return a
    else:
        return f(b,a%b)
t = sorted(t)[::-1]
l = t[0]
for i in range(1,len(t)):
    gcd = f(l,t[i])
    l = l*t[i]//gcd
print(l)