L, X, Y, S, D = map(int, input().split())
goal = (D-S) % L
print(min(goal/(X+Y), (L-goal)/abs(X-Y)) if X < Y else goal/(X+Y))