import math


def main():
    N = int(input())
    lst = [list(map(int, input().rstrip().split())) for _ in range(N)]
    print(max(euclidean_metric(lst[i], lst[j]) for i in range(N) for j in range(N)))


def euclidean_metric(t, s):
    return math.sqrt((t[0] - s[0])**2 + (t[1] - s[1])**2)


if __name__ == '__main__':
    main()