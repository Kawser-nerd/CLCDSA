N,M=map(int,input().split())
list_n=[]
for i in range(N):
    list_n.append(0)
for i in range(M):
    a,b=map(int,input().split())
    list_n[a-1]+=1
    list_n[b-1]+=1
    
for i in range(N):
    print(list_n[i])