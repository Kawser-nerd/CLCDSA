import sys
N = int(input())
a, b = map(int, input().split())
K = int(input())
P = list(map(int, input().split()))

visited = [a, b]
for p in P:
  if p in visited:
    print("NO")
    sys.exit()
  visited.append(p)

print("YES")