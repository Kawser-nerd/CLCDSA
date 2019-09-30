import sys

def solve(grid):
    count = 0
    while True:
        done = True
        for i in range(99, -1, -1):
            for j in range(99, -1, -1):
                north = i > 0 and grid[i - 1][j]
                west = j > 0 and grid[i][j - 1]
                if grid[i][j]:
                    done = False
                    if not (north or west):
                        grid[i][j] = False
                else:
                    if north and west:
                        grid[i][j] = True
        if done:
            return count
        count += 1

def main():
    T = int(input())
    for x in range(1, T + 1):
        grid = [[False for i in range(100)] for j in range(100)]
        R = int(input())
        for k in range(R):
            X1, Y1, X2, Y2 = map(int, input().split())
            for i in range(Y1 - 1, Y2):
                for j in range(X1 - 1, X2):
                    grid[i][j] = True
        print("Case #{}:".format(x), solve(grid))

if __name__ == "__main__":
    with open("C-small-attempt0.in") as sys.stdin:
        main()
