if __name__ == "__main__":
    A = int(input())
    x = A*A
    y = (A + 1) * (A + 1)
    xlst = []
    ylst = []
    while (y > 0):
        xlst += [x % 100]
        x //= 100
        ylst += [y % 100]
        y //= 100

    xans = 0
    while (xlst[-1] == ylst[-1] and sum(xlst) > 0):
        xans = xans * 100 + xlst[-1]
        xlst.pop()
        ylst.pop()

    yans = xans
    while True:
        if sum(xlst):
            xans = xans * 100 + xlst[-1]
            yans = yans * 100 + ylst[-1]
            xlst.pop()
            ylst.pop()
            if (sum(xlst) and (yans > xans + 1 or sum(ylst))):
                print(xans + 1)
                exit()
        else:
            print(xans)
            exit()