import sys
input = sys.stdin.readline

N = int(input())
A = [int(_) for _ in input().split()]
oddnum = 0

for i in A:
    if i % 2 == 1:
        oddnum += 1

print("YES" if oddnum % 2 == 0 else "NO")