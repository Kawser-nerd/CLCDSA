N, L = map(int, input().split())
s = [input() for i in range(N)]
s.sort()
print(*s, sep = "")