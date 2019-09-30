L, N = map(int, input().split())
X=[0]
sumL=[0]
sumR=[0]
for i in range(N):
    X.append(int(input()))
    sumL.append(sumL[-1]+X[-1])
for i in range(N):
    sumR.append(sumR[-1]+L-X[N-i])
sumR.append(0)
sumR.reverse()
#print(X)
#print("sumL",sumL)
#print("sumR",sumR)
ans = 0
for b in range(N+1):
    z = sumL[b] + sumR[b+1]
    if(b > 0):
        if(b <= N-b):
            ans = max(ans, z+sumL[b-1]+sumR[b+1]-2*sumR[N+1-(N-b-b)])
            #print("A", b, z+sumL[b-1]+sumR[b+1]-2*sumR[N+1-(N-b-b)])
        else:
            ans = max(ans, z+sumL[b-1]+sumR[b+1]-2*sumL[b-(N-b)-1])
            #print("B", b, z+sumL[b-1]+sumR[b+1]-2*sumL[b-(N-b)-1])
    if(b < N):
        if(b >= N-b):
            ans = max(ans, z+sumL[b]+sumR[b+2]-2*sumL[b-(N-b)])
            #print("C", b, z+sumL[b]+sumR[b+2]-2*sumL[b-(N-b)])
            #print(b, z, sumR[b+1], sumL[b], sumR[b+2], sumL[b-(N-b)])
        else:
            ans = max(ans, z+sumL[b]+sumR[b+2]-2*sumR[N+1-(N-b-b)+1])
            #print("D", b, z+sumL[b]+sumR[b+2]-2*sumR[N+1-(N-b-b)+1])
    #print("------------------------")
print(ans)