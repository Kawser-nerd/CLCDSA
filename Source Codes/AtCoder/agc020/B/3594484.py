def inpl(): return [int(i) for i in input().split()]

K = int(input())
A = list(reversed(inpl()))
X,Z = 2,2
for Ai in A:
    X = -(-X//Ai)*Ai
    if X > Z:
        print(-1)
        break
    Z = (Z//Ai)*Ai + Ai-1
else:    
    print(X, Z)