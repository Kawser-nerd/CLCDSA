# coding: utf-8

from collections import Counter, defaultdict

II = lambda: int(input())
MI = lambda: map(int, input().split())


def main():
    N, K = MI()
    C = Counter(MI())
    return N - sum((c for _, c in C.most_common(K)))


if __name__ == "__main__":
    print(main())