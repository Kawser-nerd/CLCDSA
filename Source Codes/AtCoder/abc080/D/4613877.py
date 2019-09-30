import sys

def main():
    input = sys.stdin.readline
    N, C = map(int, input().split())
    P = [list(map(int, input().split())) for _ in range(N)]
    P = sorted(P, key=lambda x: x[0])

    V = []
    for p in P:
        flag = True
        for i in range(len(V)):
            if V[i][0] < p[0]:
                V[i] = [p[1], p[2]]
                flag = False
                break
            elif V[i][0] == p[0] and V[i][1] == p[2]:
                V[i] = [p[1], p[2]]
                flag = False
                break
            else:
                continue

        if flag:
            V.append([p[1], p[2]])

    print(len(V))


if __name__ == '__main__':
    main()