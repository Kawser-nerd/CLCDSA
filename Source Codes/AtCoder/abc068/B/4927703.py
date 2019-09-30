N = int(input())
i = 1
while 2 ** i <= N:
    ans = 2 ** i
    i += 1
if N == 1:
    print(1)
else:
    print(ans)