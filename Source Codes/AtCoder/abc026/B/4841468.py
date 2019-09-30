import math
PI = math.pi

N = int(input())
R = []
for i in range(N):
    R.append(int(input()))
R = sorted(R)


ans = 0
if len(R)%2 == 1:
    ans += R[0]*R[0]*PI
    for i in range(1, len(R)):
        if i%2==0:
            ans += R[i]*R[i]*PI
            ans -= R[i-1]*R[i-1]*PI
else:
    for i in range(0, len(R)):
        if i%2==1:
            ans += R[i]*R[i]*PI
            ans -= R[i-1]*R[i-1]*PI

print(ans)