import sys
import psyco

def check(out, customer, meltfavor):
    for i, j in customer:
        if j == []:
            out[meltfavor[i] - 1] = 1

def solve(N, indexlist):
    tmp = range(N)
    out = range(N)
    location = 0
    for i in range(N):
        index = divmod(location + i, len(tmp))[1]
        location = index
        out[i] = tmp[index]
        tmp.pop(index)
    out = [i + 1 for i in out]
    output = []
    for i in indexlist:
        for ii, k in enumerate(out):
            if k == i:
                output.append(ii + 1)
    return output
        


def main():
    file = open(sys.argv[1], 'r')
    nc = int(file.readline())

    count = 1
    for case in range(nc):
        N = int(file.readline())
        indexlist = [int(i) for i in file.readline().split()]
        indexlist.pop(0)
        out = solve(N, indexlist)
        print 'Case #' + str(count) + ':', ' '.join([str(j) for j in out])
        count += 1

if __name__ == "__main__":
    #g = psyco.proxy(main)
    #g()
    main()
