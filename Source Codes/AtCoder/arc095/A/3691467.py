def inpl(): return [int(i) for i in input().split()]
N = int(input())
X = inpl()
Y = sorted(X)
a = Y[N//2-1]
b = Y[N//2]
for i in X:
    if i <= a:
        print(b)
    else:
        print(a)