#!/usr/bin/python
T = int(input())

for test in range(1, T + 1):
    N, P = [int(x) for x in input().split()]

    step = (1 << N)
    answer = 0
    while step > 0:
        if answer + step < (1 << N):
            answer += step
            aux = answer

            rounds = 0
            position = 0
            while aux >= (1 << rounds):
                aux -= (1 << rounds)
                rounds += 1
                position += (1 << (N - rounds))

            if position >= P:
                answer -= step
        step >>= 1
    answer2 = 0
    step = (1 << N)
    while step > 0:
        if answer2 + step < (1 << N):
            answer2 += step
            aux = (1 << N) - answer2 - 1

            rounds = 0
            position = (1 << N) - 1
            while aux >= (1 << rounds):
                aux -= (1 << rounds)
                rounds += 1
                position -= (1 << (N - rounds))

            if position >= P:
                answer2 -=step

        step >>= 1
    print("Case #" + str(test) + ":", answer, answer2)
