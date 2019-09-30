#!/usr/bin/env python3

from itertools import *
from collections import *
from functools import *
from math import *
# from operator import 
# hint: dir(operator)


# Read a tuple:
# length, count = map(int, input().strip().split(" "))
# reverse lookup table
# dict(zip(?, count()))

T = int(input().strip())

for t in range(T):
    print("Case #{}: ".format(t + 1), end="")
    coasterLength, nCustomers, ticketsSold = map(int, input().strip().split(" "))
    tickets = [tuple(map(int, input().strip().split(" "))) for i in range(ticketsSold)]
    customers = list(repeat(0, nCustomers))
    positions = list(repeat(0, coasterLength))
    for position, customer in tickets:
        customers[customer - 1] += 1
        positions[position - 1] += 1
    lowerBound = max(customers)
    for position, totalTickets in zip(count(1), accumulate(positions)):
        lowerBound = max(ceil(totalTickets/position), lowerBound)
        
    promotions = sum(max(0, i - lowerBound) for i in positions)
    
    print("{} {}".format(lowerBound, promotions))

