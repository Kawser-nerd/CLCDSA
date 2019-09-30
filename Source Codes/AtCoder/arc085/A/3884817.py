N,M=map(int,input().split())
E=0
i=1
a=(1900*(M)+100*(N-M))*(0.5)**(M)
while a>10e-10:
    a=(1900*(M*i)+100*(N-M)*i)*(((2**M-1)*(0.5)**M)**(i-1))*(0.5)**M
    E+=a
    i+=1
print(int(E)+1)