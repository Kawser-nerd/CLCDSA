N=int(input())
L=[]
for i in range(N):
    a,b=map(int,input().split())
    L.append([a,b])
    
#print(L)
cnt=0

for i in range(N-2):
    for j in range(i+1,N-1):
        for k in range(j+1,N):
            x=L[i][0]
            y=L[i][1]
            if (L[j][0]-x)*(L[k][1]-y)-(L[j][1]-y)*(L[k][0]-x)==0:
                pass
            elif abs((L[j][0]-x)*(L[k][1]-y)-(L[j][1]-y)*(L[k][0]-x))%2==0:
                cnt+=1
print(cnt)