N = int(input())
S = []
for i in range(N):
    S.append(input())
T = []
for i in range(N):
    tmp = ''
    for j in range(N):
        tmp += S[j][i]
    T.append(tmp[:])
#print(S)
#print(T)

ans = 0
for i in range(N):
    #print(i)
    flag = True
    for y in range(N):
        #print(S[y][i:]+S[y][:i])
        #for x in range(N):
            #if x==y:
            #    continue
            #print(x,y,(x+i)%N, S[y][(x+i)%N],S[(x+i)%N][y])
            #if S[y][(x+i)%N]!=S[(y+i)%N][x]:
        #print(y, T[(y+i)%N], S[y][i:]+S[y][:i])
        if T[(y+i)%N]!=S[y][i:]+S[y][:i]:
            flag = False
            break
    if flag:
        ans += 1

print(ans*N)