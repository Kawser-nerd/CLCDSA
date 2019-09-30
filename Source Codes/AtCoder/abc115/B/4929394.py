n = int(input())
p = [int(input()) for _ in range(n)]
p.sort()
print(sum(p) - p[-1] // 2)