A, B = map(int, input().split())

def f(n):
    digit = len(str(n))
    num = int(str(n)[0])
    if digit == 1:
        if num < 4:
            return num+1
        elif num < 9:
            return num
        else:
            return 8
    if num == 4:
        return 4 * (8**(digit-1))
    elif num == 9:
        return 8**digit
    elif num < 4:
        return f(int(str(n)[1:])) + num * (8**(digit-1))
    else:
        return f(int(str(n)[1:])) + (num-1) * (8**(digit-1))

print(B - A + 1 - (f(B) - f(A-1)))