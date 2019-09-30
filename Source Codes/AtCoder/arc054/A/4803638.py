L, X, Y, S, D = map(int, input().split())

if D > S:
    ans = (D - S) / (X + Y)
    if Y > X:
        tmp = ((L - D) + S) / (Y - X)
        ans = min(ans, tmp)
    
else:
    ans = ((L - S) + D) / (X + Y)
    if Y > X:
        tmp = (S - D) / (Y - X)
        ans = min(ans, tmp)
    
print(ans)