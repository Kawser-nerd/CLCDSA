b=[[int(i) for i in input().split()] for j in range(2)]
c=[[int(i) for i in input().split()] for j in range(3)]
memo=[None]*(1<<18)
def f(m=0,t=0):
    if t==9:
        p=0
        for y in range(3):
            for x in range(2):
                p+=0 if ((m>>(y*3+x)*2)&3)^((m>>(y*3+x+1)*2)&3) else c[y][x]
        for x in range(3):
            for y in range(2):
                p+=0 if ((m>>(y*3+x)*2)&3)^((m>>((y+1)*3+x)*2)&3) else b[y][x]
        return p
    else:
        t+=1
        result=[]
        for i in range(9):
            j=1<<i*2
            if (m>>(i*2))&3==0:
                n=m|j if t%2 else m|j*2
                if memo[n] is None:
                    memo[n]=f(n,t)
                result.append(memo[n])
        return max(result) if t%2 else min(result)
p1=f()
p2=sum(b[0]+b[1]+c[0]+c[1]+c[2])-p1
print(p1)
print(p2)