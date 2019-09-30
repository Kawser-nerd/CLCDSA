n,a,b = map(int,input().split())
ant = True
while n > 0:
    if ant:
        n -= a
    else:
        n -= b
    ant = not ant
print('Bug' if ant else 'Ant')