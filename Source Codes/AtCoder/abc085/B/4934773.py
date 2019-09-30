n = int(input())
d = [int(input()) for _ in range(n)]
mochi = sorted(set(d))
print(len(mochi))