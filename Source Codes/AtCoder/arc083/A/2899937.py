a,b,c,d,e,f = list(map(int,input().split()))
ans = []
g = 0
for i in range(f//(a*100)+1):
    for j in range((f-a*i*100)//(b*100)+1):
        for k in range(min((f-a*i*100-b*j*100)//c,e*(a*i+b*j)//c)+1):
            l = min((e*(a*i+b*j) - k*c)//d,(f-100*a*i-100*b*j-c*k)//d)
            if (a*i*100+b*j*100+c*k+d*l)>0 and (a*i*100+b*j*100+c*k+d*l)<=f:
                if g < (k*c+d*l)/(a*i*100+b*j*100+c*k+d*l):
                    g = (k*c+d*l)/(a*i*100+b*j*100+c*k+d*l)
                    ans = [a*i*100+b*j*100+c*k+d*l,k*c+d*l]
if len(ans) == 0:
    print(min(a,b)*100,0)
else:
    print(' '.join(map(str,ans)))