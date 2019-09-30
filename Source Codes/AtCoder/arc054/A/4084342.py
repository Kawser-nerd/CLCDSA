L,X,Y,S,D=map(int,input().split())
if D-S>=0:distance=D-S
else:distance=L-S+D
if X-Y<=0 and X!=Y:
    print(min(distance/(X+Y),(L-distance)/(Y-X)))
else:
    print(distance/(X+Y))