def abc_arc(x: int)->str:
    return 'ABC' if x < 1200 else 'ARC'


if __name__ == "__main__":
    x = int(input())
    ans = abc_arc(x)
    print(ans)