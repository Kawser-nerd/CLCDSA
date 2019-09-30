def L(l,a):
    return ((l-1)//a)*a+a

def R(r,a):
    return (r//a)*a+a-1
K = int(input())
x = list(map(int,input().split()))
l=2
r=2
for i in range(K):
    a = x.pop()
    l = L(l,a)
    r = R(r,a)
    if l > r:
        l = r = -1
        print(l)
        exit()

print(l,r)