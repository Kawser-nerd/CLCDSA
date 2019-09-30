N=input()
a=list(map(int,input().split()))

x=[0 for i in range(-1,10**5+10)]

for i in a:
        x[i-1]+=1
        x[i]+=1
        x[i+1]+=1

x=sorted(x)

for i in reversed(x):
        if(not i<0):
                print(i)
                exit()