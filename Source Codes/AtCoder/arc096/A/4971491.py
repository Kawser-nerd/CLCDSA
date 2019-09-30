def main():
    A, B, C, X, Y = list(map(int, input().split()))
    total = 0

    if A + B <= 2*C:
        total += X*A + Y*B
    
    else:
        if A <= 2*C and B <= 2*C:
            if X == Y:
                total += (X + Y)*C
            elif X < Y:
                total += 2*X*C
                total += (Y-X)*B
            elif X > Y:
                total += 2*Y*C
                total += (X-Y)*A
        elif A <= 2*C and B > 2*C:
            if X == Y:
                total += (X+Y)*C
            elif X < Y:
                total += 2*Y*C
            elif X > Y:
                total += 2*Y*C
                total += (X-Y)*A
        elif B <= 2*C and A > 2*C:
            if X == Y:
                total += (X+Y)*C
            elif X > Y:
                total += 2*X*C
            elif X < Y:
                total += 2*X*C
                total += (Y-X)*B
        elif A > 2*C and B > 2*C:
            total += max(X, Y)*2*C

    print(total)

main()