DIRS = {
    "R"  : ( 1,  0),
    "L"  : (-1,  0),
    "D"  : ( 0,  1),
    "U"  : ( 0, -1),
    "RD" : ( 1,  1),
    "RU" : ( 1, -1),
    "LD" : (-1,  1),
    "LU" : (-1, -1),
}
 
def step(xsrc, ysrc, wsrc):
    w = list(wsrc)
    xdst, ydst = xsrc+w[0], ysrc+w[1]
 
    if xdst < 0 or 9 <= xdst:
        w[0] *= -1
        xdst = xsrc+w[0]
    if ydst < 0 or 9 <= ydst:
        w[1] *= -1
        ydst = ysrc+w[1]
 
    return xdst, ydst, tuple(w)
 
def main():
    X, Y, W = input().split()
    X = int(X) - 1 # 0-based
    Y = int(Y) - 1
    W = DIRS[W]
 
    DIGITS = tuple(input() for _ in range(9))
 
    x, y, w = X, Y, W
    code = ""
    for _ in range(4):
        #print(x, y, w, DIGITS[y][x])
        code += DIGITS[y][x]
        x, y, w = step(x, y, w)
 
    print(code)
 
if __name__ == "__main__": main()