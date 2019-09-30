#!/usr/bin/env python3

# Google Code Jam Round 1B 2015
# Problem B. Noisy Neighbors
# Solution in Python
# By Smithers

def solve(R, C, N):
    z = N - (R * C + 1) // 2
    if z <= 0:
        return 0
    
    y = 0
    
    if R == 1 or C == 1:
        if R * C % 2 == 0:
            y += 1
            z -= 1
        y += 2 * z
        return y
    
    if R * C % 2 == 0:
        dz = min(z, 2)
        y += 2 * dz
        z -= dz
        dz = min(z, R + C - 4)
        y += 3 * dz
        z -= dz
        y += 4 * z
        return y
    
    if z == 1:
        return 3
    
    z += 1
    dz = min(z, 4)
    y += 2 * dz
    z -= dz
    dz = min(z, R + C - 6)
    y += 3 * dz
    z -= dz
    y += 4 * z
    return y

for x in range(1, int(input()) + 1):
    y = solve(*map(int, input().split()))
    
    print('Case #' + str(x) + ':', y)
