import sys
input = sys.stdin.readline

N = int(input())
a = [int(_) for _ in input().split()]
left = 0
right = 0
ans = 0
tmp = 0

while right < N:
    right += 1
    if a[right-1] > tmp:
        tmp = a[right-1]
    else:
        right -= 1
        ans += (right-left)*(right-left+1)//2
        left = right
        tmp = 0
ans += (right-left)*(right-left+1)//2

print(ans)