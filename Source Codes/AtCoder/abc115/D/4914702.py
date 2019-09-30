burger = [1 for i in range(52)]
for i in range(1,52):
    burger[i] = burger[i-1]*2+3
patty = [1 for i in range(52)]
for i in range(1,52):
    patty[i] = patty[i-1]*2 + 1
def solve(L,X):
    if X == 0:
        return 0
    if burger[L] == X:
        return patty[L]
    elif (burger[L]-1)//2 + 1 == X:
        return patty[L-1] + 1
    elif (burger[L]-1)//2 + 1 > X:
        return solve(L-1,X-1)
    elif (burger[L]-1)//2 + 1 < X:
        return patty[L-1] + 1 + solve(L-1,X-burger[L-1]-2)

N,X = list(map(int,input().split()))
print(solve(N,X))