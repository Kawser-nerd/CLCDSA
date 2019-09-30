# Marius Damarackas (m.damarackas@gmail.com)
# Google CodeJam, Round 2, 2009-09-26

M, F, best, dig = None, None, None, None

def height(row, x):
    global M, F
    rows, cols = len(M), len(M[0])
    height_ = 0
    y = row + 1
    while y < rows and M[y][x] == '.':
        height_ += 1
        y += 1
    return height_
    
def search(level, x):
    global M, F, best, dig
    rows, cols = len(M), len(M[0])
    if level == rows - 1:
        best = min(best, dig)
    else:
        left_wall = x
        while left_wall > 0 and M[level][left_wall - 1] == '.':
            left_wall -= 1
        right_wall = x
        while right_wall < cols - 1 and M[level][right_wall + 1] == '.':
            right_wall += 1
        left_base = x
        while left_base > 0 and M[level + 1][left_base - 1] == '#':
            left_base -= 1
        right_base = x
        while right_base < cols - 1 and M[level + 1][right_base + 1] == '#':
            right_base += 1
        left = max([left_wall, left_base])
        right = min([right_wall, right_base])
        if left > 0 and M[level][left - 1] == '.':
            h = height(level, left - 1)
            if h <= F:
                search(level + h, left - 1)
        if right < cols - 1 and M[level][right + 1] == '.':
            h = height(level, right + 1)
            if h <= F:
                search(level + h, right + 1)
        if left == right:
            return
        
##        if dig + 1 >= best:
##            return
##        for i in range(left, right + 1):
##            M[level + 1][i] = '.'
##            h = height(level, i)
##            if h <= F:
##                dig += 1
##                search(level + h, i)
##                dig -= 1
##            M[level + 1][i] = '#'
        
        for p in range(1, right - left + 1):
            if dig + p >= best:
                return
            for i in range(left, right - p + 2):
                for j in range(p):
                    M[level + 1][i + j] = '.'
                dig += p
                if i > left:
                    h = height(level, i)
                    if h <= F:
                        search(level + h, i)
                if i + p - 1 < right:
                    h = height(level, i + p - 1)
                    if h <= F:
                        search(level + h, i + p - 1)
                dig -= p
                for j in range(p):
                    M[level + 1][i + j] = '#'

def solve():
    global M, F, best, dig
    best = 10**9
    dig = 0
    search(0, 0)
    return "No" if best == 10**9 else "Yes " + str(best)

def main():
    global M, F
    file = open("input.in")
    tests = int(file.readline())
    for case in range(1, tests + 1):
        rows, cols, F = [int(x) for x in file.readline().split()]
        M = []
        for i in range(rows):
            M.append([x for x in file.readline().strip()])
        print("Case #", case, ": ", solve(), sep="")

if __name__ == "__main__":
    main()
