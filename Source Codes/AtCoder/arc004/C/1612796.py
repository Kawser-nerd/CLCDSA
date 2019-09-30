import fractions

def get_min(X, Y):
    left = 0
    right = 10 ** 50
    res_N = -1
    while (right - left > 1):
        med = (right + left) // 2
        if (med == 0):
            break
        y = med * Y
        x = med * X
        res = y * (y + 1) // 2
        l = res - y
        r = res - 1
        # print (med, l, r, x)
        if l <= x and x <= r:
            right = med
            res_N = med
            continue
        if x < l:
            right = med
            continue
        if x > r:
            left = med
            continue
    return res_N
if __name__ == "__main__":
    X,Y = input().split("/")
    X = int(X)
    Y = int(Y)
    g = fractions.gcd(X, Y)
    X = X // g
    Y = Y // g
    min_N = get_min(X, Y)

    if min_N == -1:
        print ("Impossible")
    else:
        t = min_N
        while (True):
            N = t * Y
            wrong = t * X
            res = N * (N + 1) // 2
            l = res - N
            r = res - 1

            if wrong < l:
                break
            if wrong > r:
                break
            print (N, res - wrong)
            t += 1