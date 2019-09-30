T = int(input())

for case in range(1, T + 1):
    t = input().split()
    J = int(t[0])
    P = int(t[1])
    S = int(t[2])
    K = int(t[3])
    print("Case #{0}: {1}".format(case, J * P * min(S, K)))
    offset = 0
    for i in range(1, J + 1):
        offset += 1
        now = offset
        for j in range(1, P + 1):
            for k in range(min(S, K)):
                now = now % S + 1
                print(' '.join([str(i), str(j), str(now)]))

