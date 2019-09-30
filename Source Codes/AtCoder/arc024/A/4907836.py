from collections import Counter


def main():
    _, _ = map(int, input().split())
    ll = Counter(map(int, input().split()))
    rr = Counter(map(int, input().split()))
    res = 0
    for l in ll.keys():
        if l in rr:
            res += min(ll[l], rr[l])
    print(res)


if __name__ == "__main__":
    main()