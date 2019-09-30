def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)

N,A = map(int,input().split())
X = sorted(map(int,input().split()))
Y = []
for x in X:
    Y.append(abs(A-x))
ans = max(Y)
for y in Y:
    ans = gcd(y,ans)
print(ans)