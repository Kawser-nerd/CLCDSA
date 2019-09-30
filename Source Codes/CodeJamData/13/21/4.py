#!/usr/bin/python
T = int(input())

for test in range(1, T + 1):
    A, N = [int(x) for x in input().split()]

    V = sorted([int(x) for x in input().split()])

    if A == 1:
        print("Case #" + str(test) + ":", N)
        continue

    answer = N
    for remove in range(N):
        oldA = A
        C = V[0:N - remove]
        add = 0
        for mote in C:
            if mote < A:
                A += mote
                continue
            while mote >= A:
                A = A * 2 - 1
                add += 1
            A += mote
        if remove + add < answer:
            answer = remove + add
        A = oldA
    print("Case #" + str(test) + ":", answer)

