import fractions
N, X = map(int, input().split())
xs = list(map(int, input().split()))
xs.append(X)
xs.sort()
dif = []
for i in range(N):
    dif.append(xs[i+1] -xs[i])
if len(dif) > 1:
    ans = fractions.gcd(dif[0], dif[1])
    for i in range(N):
        ans = fractions.gcd(ans, dif[i])
    print(ans)
else:
    print(dif[0])