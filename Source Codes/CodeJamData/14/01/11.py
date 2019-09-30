from util import *

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in xrange(num):
        g1 = int(r.next())
        row1 = []
        for j in xrange(4):
            if j == g1 - 1:
                row1 = map(int, r.next().split(" "))
            else:
                r.next()
        g2 = int(r.next())
        row2 = []
        for j in xrange(4):
            if j == g2 - 1:
                row2 = map(int, r.next().split(" "))
            else:
                r.next()

        intersection = [x for x in row1 if x in row2]
        if len(intersection) == 0:
            ans.append("Volunteer cheated!")
        elif len(intersection) == 1:
            ans.append(intersection[0])
        else:
            ans.append("Bad magician!")
    write("output", ans)

if __name__ == '__main__':
    main()
