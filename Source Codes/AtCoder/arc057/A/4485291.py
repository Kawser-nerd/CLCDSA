# -*- coding: utf-8 -*-
money = input().split()

initial_money = int(money[0])
increment = int(money[1])

goal = 2 * 10**12
counter = 0
amount = initial_money

if increment == 0:
    print(goal - amount)

else:
    while amount <  goal:
        amount += 1 + amount * increment
        counter += 1
    print(counter)