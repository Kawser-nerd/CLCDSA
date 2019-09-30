N = input()

K = len(N)
c = int(N[0])
rest_num = N[1:]

if rest_num == "9"*(K-1):
    ans = c + 9*(K-1)
else:
    ans = c-1 + 9*(K-1)

print(ans)