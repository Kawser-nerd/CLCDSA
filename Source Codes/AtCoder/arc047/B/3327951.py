#!/usr/bin/env python3

import numpy as np

def main():
    n = int(input())
    xy = []
    ez = np.empty((n, 2), dtype=np.int64)
    for i in range(n):
        x, y = map(int, input().split())
        xy.append([x, y])
        eta, zeta = x_y_to_eta_zeta(x, y)
        ez[i, 0] = eta
        ez[i, 1] = zeta

    eta_min = np.min(ez[:, 0])
    eta_max = np.max(ez[:, 0])
    zeta_min = np.min(ez[:, 1])
    zeta_max = np.max(ez[:, 1])
    d = max(eta_max - eta_min, zeta_max - zeta_min)

    for eta in [eta_max - d // 2, eta_min + d // 2]:
        for zeta in [zeta_max - d // 2, zeta_min + d // 2]:
            xp, yp = eta_zeta_to_x_y(eta, zeta)
            mds = set()
            for i in range(n):
                x, y = xy[i]
                md = manhattan_distance(x, y, xp, yp)
                mds |= {md}
            if len(mds) > 1:
                continue
            if len(mds) == 1:
                print(xp, yp)
                return

def manhattan_distance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

def x_y_to_eta_zeta(x, y):
    eta = x + y
    zeta = x - y
    return eta, zeta

def eta_zeta_to_x_y(eta, zeta):
    x = (eta + zeta) // 2
    y = (eta - zeta) // 2
    return x, y

main()