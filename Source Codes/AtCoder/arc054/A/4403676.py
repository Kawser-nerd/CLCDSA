L, X, Y, S, D = map(int, input().split())

if D - S > 0:
    tmp1 = (D - S) / (X + Y)
    tmp2 = 10 ** 10
    if Y > X:
        tmp2 = (S + (L - D)) / (Y - X)
        
    print(min(tmp1, tmp2))
else:
    tmp1 = ((L - S) + D) / (X + Y)
    tmp2 = 10 ** 10
    if Y > X:
        tmp2 = (S - D) / (Y - X)
        
    print(min(tmp1, tmp2))