N = int(input())
score = [int(input()) for i in range(N)]
ans = 0
minimum = 100
for s in score:
    ans += s
    if s % 10 != 0:
        minimum = min(minimum, s)

if ans % 10 != 0:
    print(ans)
else:
    if minimum == 100:
        print('0')
    else:
        print(ans-minimum)