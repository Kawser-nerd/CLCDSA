def red_red_red_red_blue(n: int, x: int)->int:
    return min(x-1, n-x)


if __name__ == "__main__":
    n, x = map(int, input().split())
    ans = red_red_red_red_blue(n, x)
    print(ans)