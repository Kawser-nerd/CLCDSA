def main():
    l, x, y, s, d = map(int, input().split())
    if s == d:
        print(0)
        return
    ds = [d - l, d] if s < d else [d, d + l]
    res = (ds[1] - s) / (x + y)
    if x < y:
        res = min(res, (s - ds[0]) / (y - x))
    print(res)


if __name__ == "__main__":
    main()