def inpl(): return [int(i) for i in input().split()]

X,Y = inpl()
print('Brown' if abs(X - Y) <= 1 else 'Alice')