N,M = map(int,input().split())
par = [0]*(N+2)
s_t_array = []
s_t_array.append([0,0])
for i in range(M):
    s,t = map(int,input().split())
    s_t_array.append([s,t])
    par[s] += 1
    par[t+1] -= 1

par1 = [0]*(N+2)#???????????
for i in range(1,N+1):
    par1[i] = par1[i-1]+par[i]

par2 = [0]*(N+2) #??????????????????
for i in range(1,len(par)):
    if par1[i] != 1:
        par1[i] = 0
    par2[i] = par2[i-1] + par1[i]

ans = []

for i in range(1,M+1):
    if par2[s_t_array[i][1]] - par2[(s_t_array[i][0]-1)] == 0:
        ans.append(i)

print(len(ans))
if len(ans)!= 0:
    for i  in ans:
        print(i)