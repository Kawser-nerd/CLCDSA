# coding: utf-8

from fractions import Fraction
from collections import Counter, defaultdict

II = lambda: int(input())
MI = lambda: map(int, input().split())


def main():
    A, B, C, D, E, F = MI()
    A *= 100
    B *= 100

    water_ws = set()
    for a in range(F//A + 1):
        for b in range(F//B + 1):
            w = a * A + b * B
            if w <= F: water_ws.add(w)
    water_ws.remove(0)
    sugar_w_max = max([ww // 100 * E for ww in water_ws])
    sugar_ws = set()
    for c in range(sugar_w_max // C):
        for d in range(sugar_w_max // D):
            w = c * C + d * D
            if w <= sugar_w_max: sugar_ws.add(w)
    ans_w, ans_s = A, 0
    dens_max = -1
    for ww in water_ws:
        for sw in sugar_ws:
            dens = Fraction(sw, ww + sw)
            if ww + sw <= F and sw <= ww // 100 * E and dens > dens_max:
                ans_w = ww + sw
                ans_s = sw
                dens_max = dens
    print(ans_w, ans_s)


if __name__ == "__main__":
    main()