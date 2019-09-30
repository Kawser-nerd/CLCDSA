def solve():
    for i in range(1, 10):
        print("? {}".format(10**i))
        ans = input()
        if ans == "N":
            solve2(i)
            return
    solve1()

def solve2(i):
    '''10**(i-1) + 1 <= 10**i - 1 ??????????
    ????????????0???????????
    '''
    lower = 10**(i - 1)
    upper = 10**i - 1
    while (upper - lower > 1):
        mid = (lower + upper)//2
        print("? {}0".format(mid))
        ans = input()
        if ans == "Y":
            upper = mid
        else:
            lower = mid
    print("! {}".format(upper))

def solve1():
    '''1, 10, 100, ... 10**9 ??????????
    '''
    for i in range(10):
        print("? {}".format(2 * 10**i))
        ans = input()
        if ans == "Y":
            print("! {}".format(10**i))
            return

solve()