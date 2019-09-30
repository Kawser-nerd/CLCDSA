N,L = list(map(int,input().split()))

a = list(map(int,input().split()))

a_list = []
for i in range(N-1):
    a_list.append([a[i]+a[i+1],i])
    
a_list=sorted(a_list,key=lambda x:x[0],reverse=True)

if a_list[0][0]>=L:
    n=a_list[0][1] 
    print("Possible")
    for i in range(n):
        print(i+1)
    for i in range(N-2-n):
        print(N-1-i)
    print(n+1)
else:
    print("Impossible")