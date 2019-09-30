import sys

def dah(n,r,t):
    return 2*n*r + n + 2*n*(n-1) <= t

def main():
    data = sys.stdin.readlines()
    case = 1
    for line in data[1:]:
        line = line.split()
        r = int(line[0])
        t = int(line[1])
        men = 0
        mai = 10**20
        while men!=mai:
            med = (men+mai)/2
            if dah(med,r,t):
                men = med+1
            else:
                mai = med

        while not dah(men,r,t):
            men -= 1
        print "Case #" + str(case) + ": " +  str(men)
        case += 1

main()
