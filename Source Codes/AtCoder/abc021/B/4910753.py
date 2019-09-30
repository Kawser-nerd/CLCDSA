N = int(input())
a, b = map(int, input().split())
K = int(input())
P = list(map(int, input().split()))
counts = []
for p in set(P):
    counts.append(P.count(p))

if a in P or b in P:
    print("NO")
elif max(counts) > 1:
    print("NO")
else:
    print("YES")