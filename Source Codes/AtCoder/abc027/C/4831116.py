n=int(input())
i=0
while 2**i<=n:
    i+=1
    
if i%2==0:
    def t(x):
        return 2*x
    def a(x):
        return 2*x+1
else:
    def a(x):
        return 2*x
    def t(x):
        return 2*x+1
    
x=1
j=0
while x<=n:
    if j%2==0:
        x=t(x)
    else:
        x=a(x)
    j+=1

if j%2==0:
    print("Takahashi")
else:
    print("Aoki")