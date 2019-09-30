#!/usr/bin/env python3

def main():
    K = int(input())

    d = [100] * K
    d[1] = 1
    Q = []
    for i in range(45 + 1):
        Q.append([])
    Q[1].append(1)
    for i in range(1, 45 + 1):
        q = Q[i]
        while 0 < len(q):
            v = q.pop(0)
            nv = (v * 10) % K
            if i < d[nv]:
                d[nv] = i
                q.append(nv)
            nnv = (v + 1) % K
            if i + 1 < d[nnv]:
                d[nnv] = i + 1
                Q[i + 1].append(nnv)



    print(d[0])


if __name__ == '__main__':
    main()