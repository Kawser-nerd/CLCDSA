#!/usr/bin/env python

f = open("A.in", "rt")

def main():
    T = int(f.readline().strip())
    for test in range(T):
        N = int(f.readline().strip())
        v = []
        for i in range(N):
            line = f.readline().strip()
            cur = 0
            for j in range(len(line)):
                if line[j] == '1':
                    cur = j + 1
            v.append(cur)

        count = 0
        for i in range(len(v) - 1):
            if v[i] > i + 1:
                for j in range(i + 1, len(v)):
                    if v[j] <= i + 1:
                        aux = v[j]
                        for k in range(j, i, -1):
                            v[k] = v[k - 1]
                            count += 1
                        v[i] = aux
                        break

        print "Case #%d: %s" % (test + 1, count)
    return 0

if __name__ == "__main__":
    main()

