import math

N, H = map(int, input().rstrip().split())
A, B, C, D, E = map(int, input().rstrip().split())

money = -1
for i in range(N+1):
    X = i
    YY = ((N-X)*E - H - B*X)/(D + E)
    Y = math.ceil(YY)
    if Y == YY:
        Y += 1
    if Y < 0:
        Y = 0
    if money == -1:
        money = A*X + C*Y
    else:
        if A*X + C*Y < money:
            money = A*X + C*Y

print(money)