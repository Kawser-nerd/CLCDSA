#ABC110 B 

#??
N, M, X, Y = list(map(int, input().split()))
x = list(map(int, input().split()))
y = list(map(int, input().split()))

#??
isnotWar = False
if X < Y:
    for Z in range(X+1,Y+1): 
        if max(x) < Z and min(y) >= Z:
            isnotWar = True
            
if isnotWar:
    print("No War")
else:
    print("War")