import sys
import psyco

def check(out, customer, meltfavor):
    for i, j in customer:
        if j == []:
            out[meltfavor[i] - 1] = 1

def solve(N, customer, meltfavor):
    out = [0 for i in range(N)]
    check(out, customer, meltfavor)

def allco(n,a,b,c,d,x0,y0,m):
    out = []
    out.append((x0,y0))
    x = x0
    y = y0
    total = 0
    for i in range(n - 1):
        x = (a * x + b) % m
        y = (c * y + d) % m
        out.append((x,y))
        if i >= 1: # len(out) = i + 2
            for j in range(i):
                for k in range(j + 1, i + 1):
                    if divmod(out[j][0] + out[k][0] + out[-1][0], 3)[1] == 0 and divmod(out[j][1] + out[k][1] + out[-1][1], 3)[1] == 0:
                        total += 1
    return total
    



def main():
    file = open(sys.argv[1], 'r')
    nc = int(file.readline())

    count = 1
    for line in file:
        N = [int(i) for i in line.split()]
        n = N[0]
        a = N[1]
        b = N[2]
        c = N[3]
        d = N[4]
        x0 = N[5]
        y0 = N[6]
        m = N[7]
        total = allco(n,a,b,c,d,x0,y0,m)
        print 'Case #' + str(count) + ':', total
        count += 1

if __name__ == "__main__":
    #g = psyco.proxy(main)
    #g()
    main()
