#!/usr/bin/env python3

from math import floor, ceil

def read_ints():
    return list(map(int, input().split(' ')))

def servings(ratio, quantity):
    return ceil(100 * quantity / (110 * ratio)), floor(100 * quantity / (90 * ratio))

def get_min(pair):
    return pair[0]

def get_max(pair):
    return pair[1]

def valid(ratio, quantity):
    the_min, the_max = servings(ratio, quantity)
    return the_min <= the_max and the_max > 0

def solve(ratios, ingredients):
    n = len(ratios)
    count = 0
    ingredients = [[quantity for quantity in quantities if valid(ratio, quantity)] for ratio, quantities in zip(ratios, ingredients)]
    if any(quantities == [] for quantities in ingredients):
        return count
    lims = [servings(ratio, quantities.pop()) for ratio, quantities in zip(ratios, ingredients)]
    while True:
        while True:
            the_min = max(map(get_min, lims))
            for i in range(n):
                while get_max(lims[i]) < the_min:
                    if ingredients[i] == []:
                        return count
                    lims[i] = servings(ratios[i], ingredients[i].pop())
            worst_min = max(map(get_min, lims))
            worst_max = min(map(get_max, lims))
            if worst_min <= worst_max:
                break
        count += 1
        for i in range(n):
            if ingredients[i] == []:
                return count
            lims[i] = servings(ratios[i], ingredients[i].pop())
    return count

def main():
    t = int(input())
    for ti in range(t):
        n, p = read_ints()
        ratios = read_ints()
        ingredients = [sorted(read_ints(), reverse=True) for _ in range(n)]
        print("Case #{}: {}".format(ti+1, solve(ratios, ingredients)))

if __name__ == '__main__':
    main()
