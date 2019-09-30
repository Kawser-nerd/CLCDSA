N = input()

K = len(N)
c = int(N[0])
rest_num = N[1:]

if K == 1 or set(rest_num) == {"9"}:
    ans = c + 9*(K-1)
else:
    ans = c-1 + 9*(K-1)

print(ans)