def main():
    a = [[int(s) for s in input().split()] for _ in range(4)]

    if solve(a):
        print('CONTINUE')
    else:
        print('GAMEOVER')

def solve(a):
    for r in range(4):
        for c in range(3):
            if a[r][c] == a[r][c+1]:
                return True

    for r in range(3):
        for c in range(4):
            if a[r][c] == a[r+1][c]:
                return True

    return False

main()