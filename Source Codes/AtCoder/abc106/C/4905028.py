def solve(s, k):
    for i, d in enumerate(map(int, list(s))):
        if i == k-1:
            return s[k-1]
        if d > 1:
            return d
    return 1

s = input()
k = int(input())
print(solve(s, k))