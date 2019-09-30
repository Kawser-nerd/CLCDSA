from collections import Counter

if __name__ == '__main__':
    n = int(input())
    a = [int(s) for s in input().split()]
    print(max(Counter(a + [x - 1 for x in a] + [x + 1 for x in a]).values()))