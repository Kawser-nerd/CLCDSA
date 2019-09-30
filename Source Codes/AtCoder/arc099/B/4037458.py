f=lambda x:sum(map(int,str(x)))
ans=[]

def check(x):
    y=f(x)
    while ans:
        p=ans[-1]
        if p*y>x*f(p):ans.pop(-1)
        else:break
    ans.append(x)

k=int(input())
for i in range(1,100):
    check(i)
a,b=0,1
while a<1e12:
    for i in range(100,1000):
        check(i*b+a)
    a=a*10+9
    b*=10

for i in range(k):
    print(ans[i])