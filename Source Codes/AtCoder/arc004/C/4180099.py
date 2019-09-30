X, Y = map(int, input().split("/"))
gcd, _ = X, Y
while _:
    gcd, _ = _, gcd%_
X = _X = X//gcd
Y = _Y = Y//gcd
ans = []

ng, ok = 0, 10**100
while ok-ng > 1:
    mid = (ok+ng)//2
    if Y*mid*(Y*mid+1)//2 - mid*X > 0:
        ok = mid
    else:
        ng = mid

X, Y = X*ok, Y*ok

while True:
    M = Y*(Y+1)//2 - X
    if 0 < M <= Y:
        ans.append([Y, M])
    elif M > Y:
        break

    X, Y = X+_X, Y+_Y

if ans:
    print(*(" ".join(map(str, l)) for l in ans), sep="\n")
else:
    print("Impossible")