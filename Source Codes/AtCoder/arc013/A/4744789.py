def main():
    x1, y1, z1 = map(int, input().split())
    x2, y2, z2 = map(int, input().split())
    print(solve(x1, y1, z1, x2, y2, z2))

def solve(x1, y1, z1, x2, y2, z2):
    r = 0

    r = max(r, (x1 // x2) * (y1 // y2) * (z1 // z2))
    r = max(r, (x1 // x2) * (y1 // z2) * (z1 // y2))
    r = max(r, (x1 // y2) * (y1 // x2) * (z1 // z2))
    r = max(r, (x1 // y2) * (y1 // z2) * (z1 // x2))
    r = max(r, (x1 // z2) * (y1 // x2) * (z1 // y2))
    r = max(r, (x1 // z2) * (y1 // y2) * (z1 // x2))

    return r

main()