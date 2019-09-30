#!/usr/bin/python3

import sys

t = int(sys.stdin.readline())

def solve(p, q, monsters, diana):
    # diana = how many shoots ahead
    if len(monsters) == 0:
        return 0
    hp, gold = monsters[0]
    shoots = hp // q + (1 if hp % q != 0 else 0)
    best = solve(p, q, monsters[1:], diana + shoots) # Diana lets it get killed
    # Diana kills it
    while hp - q > 0:
        diana += 1
        hp -= q
    shoots = hp // p + (1 if hp % p != 0 else 0)
    if shoots <= diana:
        # She can kill it!
        value = gold + solve(p, q, monsters[1:], diana - shoots)
        best = max(best, value)
    return best     

for test_case in range(1, t+1):
    p, q, n = map(int, sys.stdin.readline().strip().split())
    monsters = []
    for i in range(n):
        h, g = map(int, sys.stdin.readline().strip().split())
        monsters.append((h, g))
    print("Case #{0}: {1}".format(test_case, solve(p, q, monsters, 1)))
