n = int(input())
s_ = [input() for i in range(n)]

s_list = [0, 0, 0, 0, 0]
for i in range(n):
    if s_[i][0] == 'M':
        s_list[0] += 1
    elif s_[i][0] == 'A':
        s_list[1] += 1
    elif s_[i][0] == 'R':
        s_list[2] += 1
    elif s_[i][0] == 'C':
        s_list[3] += 1
    elif s_[i][0] == 'H':
        s_list[4] += 1

import math
counter = 0
s_list_nonzero = []
for i in range(5):
    if s_list[i] != 0:
        counter += 1
        s_list_nonzero.append(s_list[i])

if counter < 3:
    print(0)
elif counter == 3:
    print(s_list_nonzero[0] * s_list_nonzero[1] * s_list_nonzero[2])
elif counter == 4:
    print(s_list_nonzero[0] * s_list_nonzero[1] * s_list_nonzero[2] +
            s_list_nonzero[0] * s_list_nonzero[1] * s_list_nonzero[3] +
            s_list_nonzero[0] * s_list_nonzero[2] * s_list_nonzero[3] +
            s_list_nonzero[1] * s_list_nonzero[2] * s_list_nonzero[3])
elif counter == 5:
    print(s_list_nonzero[0] * s_list_nonzero[1] * s_list_nonzero[2] +
            s_list_nonzero[0] * s_list_nonzero[1] * s_list_nonzero[3] +
            s_list_nonzero[0] * s_list_nonzero[1] * s_list_nonzero[4] +
            s_list_nonzero[0] * s_list_nonzero[2] * s_list_nonzero[3] +
            s_list_nonzero[0] * s_list_nonzero[2] * s_list_nonzero[4] +
            s_list_nonzero[0] * s_list_nonzero[3] * s_list_nonzero[4] +
            s_list_nonzero[1] * s_list_nonzero[2] * s_list_nonzero[3] +
            s_list_nonzero[1] * s_list_nonzero[2] * s_list_nonzero[4] +
            s_list_nonzero[1] * s_list_nonzero[3] * s_list_nonzero[4] +
            s_list_nonzero[2] * s_list_nonzero[3] * s_list_nonzero[4])