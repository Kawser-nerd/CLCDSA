#!/usr/bin/env python3

# Google Code Jam Round 2 2015
# Problem D. Drum Decorator
# Solution in Python
# By Smithers

for x in range(1, int(input()) + 1):
    R, C = map(int, input().split())
    
    table = [None] * (R + 1)
    
    #    12s next, 3s next
    #  1
    #  3
    #  4
    #  6
    # 12
    table[0] = [[1, 1],
                [0, 0],
                [0, 0],
                [0, 0],
                [0, 0]]
    
    for i in range(1, R+1):
        table[i] = [[0, 0],
                    [0, 0],
                    [0, 0],
                    [0, 0],
                    [0, 0]]
        
        # ...3...
        # ...3...
        if i >= 2:
            table[i][0][0] += table[i-2][0][1]
            table[i][1][0] += table[i-2][1][1]
            table[i][2][0] += table[i-2][2][1]
            table[i][3][0] += table[i-2][3][1]
            table[i][4][0] += table[i-2][4][1]
        
        # ...2...
        table[i][0][1] += table[i-1][0][0]
        table[i][1][1] += table[i-1][1][0]
        table[i][2][1] += table[i-1][2][0]
        table[i][3][1] += table[i-1][3][0]
        table[i][4][1] += table[i-1][4][0]
    
        # ...122...
        # ...122...
        if i >= 2 and C % 3 == 0:
            table[i][1][1] += 1 * table[i-2][0][0]
            table[i][1][1] += 3 * table[i-2][1][0]
            table[i][4][1] += 1 * table[i-2][2][0]
            table[i][3][1] += 3 * table[i-2][3][0]
            table[i][4][1] += 3 * table[i-2][4][0]
        
        # ...112222...
        # ...222112...
        if i >= 2 and C % 6 == 0:
            table[i][3][1] += 1 * table[i-2][0][0]
            table[i][3][1] += 3 * table[i-2][1][0]
            table[i][4][1] += 2 * table[i-2][2][0]
            table[i][3][1] += 6 * table[i-2][3][0]
            table[i][4][1] += 6 * table[i-2][4][0]
        
        # ...2122...
        # ...2121...
        # ...2221...
        if i >= 3 and C % 4 == 0:
            table[i][2][1] += 1 * table[i-3][0][0]
            table[i][4][1] += 1 * table[i-3][1][0]
            table[i][2][1] += 4 * table[i-3][2][0]
            table[i][4][1] += 2 * table[i-3][3][0]
            table[i][4][1] += 4 * table[i-3][4][0]
    
    y = sum(map(sum, table[R])) % 1000000007
    
    print('Case #' + str(x) + ':', y)
