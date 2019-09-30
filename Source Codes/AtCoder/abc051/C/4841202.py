def back_and_forth(sx: int, sy: int, tx: int, ty: int)->int:
    dx, dy = tx - sx, ty - sy
    forth = ('U' * dy) + ('R' * dx)
    back = ('D' * dy) + ('L' * dx)
    first = forth + back
    second = 'LU' + forth + 'RD' + 'RD' + back + 'LU'

    return first + second


if __name__ == "__main__":
    sx, sy, tx, ty = map(int, input().split())
    ans = back_and_forth(sx, sy, tx, ty)
    print(ans)