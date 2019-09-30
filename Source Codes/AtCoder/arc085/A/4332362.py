N,M=map(int,input().split())


m=2**M
ans=0
i=1
while True:
        k=( (1*((1/m))) * ((( (m-1)/m)**(i-1)) )) * ( 1900*M*i +(N-M)*100*i)#       +( (1*((1/m))) * ((( (m-1)/m)**(i-1)) )) *
        ans+=k
        i+=1
        if(i>10000):
                break

print(int(ans+0.5))