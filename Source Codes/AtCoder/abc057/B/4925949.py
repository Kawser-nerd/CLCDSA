N,M=map(int,input().split())
a_list=[]
b_list=[]
for i in range(N):
    a,b=map(int,input().split())
    a_list.append(a)
    b_list.append(b)
    
c_list=[]
d_list=[]
for i in range(M):
    c,d=map(int,input().split())
    c_list.append(c)
    d_list.append(d)

for i in range(N):
    sum=1000000000
    for j in range(M):
        key=abs(a_list[i]-c_list[j])+abs(b_list[i]-d_list[j])
        if sum>key:
            ans=j+1
            sum=key
    print(ans)