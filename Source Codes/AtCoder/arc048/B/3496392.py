N = int(input())

participant = []
hand_list = [[0]*3 for i in range(100001)]
rating_acum = [0 for i in range(100001)]

for i in range(N):
    r, h = map(int, input().split())
    participant.append([r, h])
    rating_acum[r] += 1
    if h == 1:
        hand_list[r][0] += 1
    elif h == 2:
        hand_list[r][1] += 1
    else:
        hand_list[r][2] += 1

from itertools import accumulate
import operator
rating_acum = list(accumulate(rating_acum, operator.add))

for i in range(N):
    r = participant[i][0]
    h = participant[i][1]
    ac = rating_acum[r-1]
    G = hand_list[r][0]
    C = hand_list[r][1]
    P = hand_list[r][2]
    if h == 1:
        print(ac + C, N - ac - G - C, G - 1)

    elif h == 2:
        print(ac + P, N - ac - P - C, C - 1)
    else:
        print(ac + G, N - ac - G - P, P - 1)