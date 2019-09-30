# use faster method than input()
import sys
input = sys.stdin.readline

H, W = map(int, input().split())
N = int(input())
A = list(map(int, input().split()))

l = [0]*(H*W)
prev = 0
for i, a in enumerate(A):
    color = i+1
    cnt = 0
    while cnt < a:
        l[cnt+prev] = color
        cnt += 1
    prev = prev+a

for i in range(H):
    sub_l = l[W*i:W*(i+1)]
    if i % 2 == 0:
        print(" ".join(map(str, sub_l)))
    else:
        sub_l = sub_l[::-1]
        print(" ".join(map(str, sub_l)))