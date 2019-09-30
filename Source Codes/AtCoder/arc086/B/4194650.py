N = int( input())
A = list( map( int, input().split()))
B = [ ( abs(A[i]), i) for i in range(N)]
B.sort( key=None, reverse = True)
_,s = B[0]
ans = 0
ANS = []
if A[s] == 0:
    pass
else:
    for i in range(N):
        if i == s:
            continue
        ANS.append( str(s+1) + " " + str(i+1))
        ans += 1
    if A[s] > 0:
        for i in range(N-1):
            ANS.append( str(i+1) + " " + str(i+2))
            ans += 1
    else:
        for i in range(N-1, 0, -1):
            ANS.append( str(i+1) + " " + str(i))
            ans += 1
print(ans)
for i in range(ans):
    print( ANS[i])