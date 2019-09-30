from collections import Counter

if __name__ == '__main__':
    n, k = map(int, input().split())
    a = sorted(Counter(int(s) for s in input().split()).values())
    print(sum(a[:len(a) - k]))