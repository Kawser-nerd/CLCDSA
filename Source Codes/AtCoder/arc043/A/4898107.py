def main():
    n, a, b = map(int, input().split())
    ss = [int(input()) for _ in range(n)]
    s_min = min(ss)
    s_max = max(ss)
    if s_min == s_max:
        print(-1)
        return
    p = b / (s_max - s_min)
    q = a - sum(ss) * p / n
    print(p, q)


if __name__ == "__main__":
    main()