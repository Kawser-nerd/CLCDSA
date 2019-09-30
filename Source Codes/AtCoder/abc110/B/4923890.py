N,M,X,Y=map(int, input().split())
x=max(map(int, input().split()))
y=min(map(int, input().split()))

c1 = set(range(X+1, Y+1))
c2 = set(range(x+1, y+1))

print("No War" if len(c1&c2) > 0 else "War")