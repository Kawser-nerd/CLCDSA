N = int(input())

red = 0
blue = 0
for _ in range(N):
    item = input()
    red += item.count('R')
    blue += item.count('B')

ans = 'DRAW'
if blue < red:
    ans = 'TAKAHASHI'
elif blue > red:
    ans = 'AOKI'

print(ans)