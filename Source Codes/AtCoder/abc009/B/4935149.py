N = int(input())
l = [int(input()) for _ in range(N)]
l = list(set(l))
l.sort()
print(l[-2])