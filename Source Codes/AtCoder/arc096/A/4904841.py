A, B, C, X, Y = map(int, input().rstrip().split())
AB = C*2
if A+B < AB:
    print(A*X+B*Y)
else:
    answer = AB*min(X,Y) + A*(X-Y) if X > Y else AB*min(X,Y) + B*(Y-X)
    answer = AB*max(X,Y) if AB*max(X,Y) < answer else answer
    print(answer)