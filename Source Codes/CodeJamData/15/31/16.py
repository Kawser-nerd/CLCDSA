
def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret


def top(C, W):
    return C / W

def last(C, W):
    if C == W:
        return W
    elif C < W * 2:
        return 1 + W
    elif C == W * 2:
        return min(1+W, 1+W)
    elif C % W == 0:
        return min(C/W + W - 1, C/W-1 + W)
    else: # W > C * 2
        return C/W + W

def main():
    for t in range(1, 1+input()):
        R, C, W = read_array(int)
        ans = (R-1) * top(C, W)
        ans += last(C, W)

        print "Case #%d: %d" % (t, ans)


main()
