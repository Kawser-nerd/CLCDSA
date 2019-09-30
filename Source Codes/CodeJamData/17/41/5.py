#!/usr/bin/env python3

from itertools import *
from collections import *
from functools import *
from operator import floordiv, mul, sub
# hint: dir(operator)


# Read a tuple:
# length, count = map(int, input().strip().split(" "))
# reverse lookup table
# dict(zip(?, count()))

strategies = {
    2: [(1, (1, 0)),
        (1, (0, 2))
        ],
    3: [(1, (1, 0, 0)),
        (1, (0, 1, 1)),
        (1, (0, 3, 0)),
        (1, (0, 0, 3))
        ],
    4: [(1, (1, 0, 0, 0)),
        (1, (0, 1, 0, 1)),
        (1, (0, 0, 2, 0)),
        (1, (0, 2, 1, 0)),
        (1, (0, 0, 1, 2)),
        (1, (0, 4, 0, 0)),
        (1, (0, 0, 0, 4)),
        ]
    }

T = int(input().strip())

for t in range(T):
    print("Case #{}: ".format(t + 1), end="")
    ngroups, packsize = map(int, input().strip().split(" "))
    groups = map(int, input().strip().split(" "))
    strategy = strategies[packsize]
    modgroups = list(repeat(0, packsize))
    for i in groups:
        modgroups[i%packsize] += 1
    score = 0
    #print(modgroups)
    for value, operation in strategy:
        repetitions = min(map(lambda a, b: a // b if b != 0 else float('inf'), modgroups, operation))
        #print(repetitions, operation)
        modgroups = list(map(sub, modgroups, map(mul, operation, repeat(repetitions))))
        score += value*repetitions
    if sum(modgroups) > 0:
        score += 1
        #print("bonus")
    #print(modgroups)
    print(score)

