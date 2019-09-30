def check(balloons, n):
    latests = [(n-x[0])//x[1] for x in balloons]
    for i, latest in enumerate(sorted(latests)):
        if i > latest:
            return False
    return True


def main():
    N = int(input())
    balloons = [tuple(map(int, input().split())) for _ in range(N)]
    left = 0
    right = int(1e15)
    while left < right:
        center = (left + right) // 2
        if check(balloons, center):
            right = center
        else:
            left = center + 1
    print(left)


if __name__ == "__main__":
    main()