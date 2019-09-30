T  = int(input())
def gcd(a,b):
    if b==0: return a
    return gcd(b, a%b)
for _ in range(T):
    a,b,c,d =list( map(int, input().split()) )
    if a<b or d<b:
        print('No')
        continue
    a %= b
    d%=b
    d = gcd(d,b)
    if c>= b:
        print('Yes')
        continue
    x = (b-a)//d
    y = a+ x*d
    if y == b: y-=d
    if y>c:
        print('No')
    else:
        print('Yes')