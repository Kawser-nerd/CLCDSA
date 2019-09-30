# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
N, M = map(int, input().split())
node = [0]*(N+1)
for _ in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    node[a] += 1
    node[b] += 1

if all(x % 2 == 0 for x in node):
    print("YES")
else:
    print("NO")