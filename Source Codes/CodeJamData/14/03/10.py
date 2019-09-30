from util import *

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in xrange(num):
        R, C, M = map(int, r.next().split(" "))

        empty = R * C - M
        width = C
        height = R

        if empty == 0:
            ans.append("\nImpossible")
            continue

        if empty == 1:
            s = "\n"
            for j in xrange(R):
                if j == 0:
                    s += "c" + "*" * (C - 1) + "\n"
                else:
                    s += "*" * C + "\n"
            ans.append(s[:-1])
            continue

        if R == 1:
            ans.append("\n" + "c" + "." * (empty - 1) + "*" * (C - empty))
            continue

        flag1 = False
        flag2 = False

        while True:
            rows, extra = empty / width, empty % width
            if rows + (extra > 0) > R:
                flag1 = True
                break
            if extra != 1 and rows > 1:
                s = ""
                for j in xrange(R):
                    if j < rows:
                        s += "." * width + "*" * (C - width) + "\n"
                    elif j == rows:
                        s += "." * extra + "*" * (C - extra) + "\n"
                    else:
                        s += "*" * C + "\n"
                ans.append("\nc" + s[1:-1])
                break
            width -= 1
            if width < 2:
                flag1 = True
                break

        while flag1:
            cols, extra = empty / height, empty % height
            if cols + (extra > 0) > C:
                flag2 = True
                break
            if extra != 1 and cols > 1:
                s = ""
                for j in xrange(R):
                    if j < extra:
                        s += "." * (cols + 1) + "*" * (C - cols - 1) + "\n"
                    else:
                        s += "." * cols + "*" * (C - cols) + "\n"
                ans.append("\nc" + s[1:-1])
                break
            height -= 1
            if height < 2:
                flag2 = True
                break 

        while flag2:
            if M > (R - 2) * (C - 2):
                ans.append("\nImpossible")
                break
            else:
                rows, extra = M / (C - 2), M % (C - 2)
                s = ""
                for j in xrange(R):
                    if j < R - rows - (extra > 0):
                        s += "." * C + "\n"
                    elif j == R - rows - (extra > 0):
                        s += "." * (C - extra) + "*" * extra + "\n"
                    else:
                        s += ".." + "*" * (C - 2) + "\n"
                ans.append("\nc" + s[1:-1])
                break


    write("output", ans)

if __name__ == '__main__':
    main()
