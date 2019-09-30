N, D = map(int, input().split())
X, Y = map(int, input().split())

fact = [1]
for i in range(1, 1001):
    fact.append(fact[-1] * i)

if X % D != 0 or Y % D != 0:
    print(0)
else:
    X = abs(X//D)
    Y = abs(Y//D)
    
    if X + Y > N or (X+Y+N) % 2 != 0:
        print(0)
    else:
        ans = 0
        for a in range((N-(X+Y))//2+1):
            b = (N-(X+Y))//2 - a
            ans += fact[N] / (fact[X+a]*fact[a]*fact[Y+b]*fact[b]*(4**N))
        
        print(ans)