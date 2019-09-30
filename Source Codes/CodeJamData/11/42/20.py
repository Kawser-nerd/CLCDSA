import sys

def spinning_blade(R, C, D, ms):
    ms = list(reversed(ms))
    for K in reversed(range(3, min(R, C) + 1)):
        for i in range(0, R-K+1):
            for j in range(0, C-K+1):
                cm = [0, 0]
                m = 0
                for x in range(0, K):
                    for y in range(0, K):
                        a = ms[y+j][x+i]
                        cm[0] += x*a
                        cm[1] += y*a
                        m += a
                m -= ms[j][i]
                a = ms[j+K-1][i]; cm[1] -= (K-1)*a; m -= a
                a = ms[j][i+K-1]; cm[0] -= (K-1)*a; m -= a
                a = ms[j+K-1][i+K-1]; cm[0] -= (K-1)*a; cm[1] -= (K-1)*a; m -= a
                if cm[0] == cm[1] == (K - 1) * m / 2: return str(K)
    return "IMPOSSIBLE"
                
        

def main(filename):
    Input = open(filename, 'r').read().split('\n')
    Output = ""
    x = 0
    for i in range(1, int(Input[0]) + 1):
        (R, C, D) = [int(j) for j in Input[i+x].split(' ')]
        ms = [[int(k) for k in list(Input[i+x+j])] for j in range(1, R+1)]
        x += R
        result = spinning_blade(C, R, D, ms)
        Output += "Case #" + str(i) + ": " + result + "\n"
    open(filename[:-3] + ".out", 'w').write(Output)

if __name__ == "__main__": main(sys.argv[1])
