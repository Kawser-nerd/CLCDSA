#!/usr/bin/env python3

ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def main():
    def find(p):
        return p if parents[p] == p else find(parents[p])

    def union(x, y):
        parents[find(y)] = find(x)

    n = int(input())
    s1 = input()
    s2 = input()

    used = set()
    for c in s1 + s2:
        if c in ABC:
            used.add(c)
    parents = {a:a for a in used}

    for i in range(n):
        if s1[i] in ABC and s2[i] in ABC:
            union(s1[i], s2[i])

    groups = {find(a) for a in used}
    possible = {g:{0, 1, 2, 3, 4, 5, 6, 7, 8, 9} for g in groups}

    for c in [s1[0], s2[0]]:
        if c in ABC:
            g = find(c)
            possible[g] -= {0}

    for i in range(n):
        if s1[i] in ABC and s2[i] not in ABC:
            possible[find(s1[i])] = {s2[i]}
        if s1[i] not in ABC and s2[i] in ABC:
            possible[find(s2[i])] = {s1[i]}

    cnt = 1
    for g in groups:
        cnt *= len(possible[g])

    print(cnt)

main()