X, Y = [int(_) for _ in input().split()]

cache = {}

def calc(X, Y):
    if X < Y:
        X, Y = Y, X
    def cal(X, Y):
        if X <= 1:
            return False
        for n in range(1, X // 2 + 1):
            if calc(X - n * 2, Y + n) == False:
                return True
        for n in range(1, Y // 2 + 1):
            if calc(X + n, Y - n * 2) == False:
                return True
        return False
    k = (X, Y)
    if k in cache:
        return cache[k]
    r = cal(X, Y)
    cache[k] = r
    return r

def calc1(X, Y):
    if abs(X - Y) < 2:
        return False
    return True

if calc1(X, Y):
    print("Alice")
else:
    print("Brown")