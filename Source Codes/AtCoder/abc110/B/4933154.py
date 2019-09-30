N, M, X, Y = map(int,input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))


x_max  = max(x)
y_min = min(y)
if x_max >= y_min or x_max >= Y or y_min <= X:
    print("War")
else :
    print("No War")