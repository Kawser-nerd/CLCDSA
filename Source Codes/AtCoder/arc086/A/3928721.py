# -*- coding: utf-8 -*-


def main():
    from collections import Counter

    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0

    for index, (key, ai) in enumerate(sorted(Counter(a).items(), key=lambda x: x[1], reverse=True), 1):
        if index > k:
            ans += ai

    print(ans)


if __name__ == '__main__':
    main()