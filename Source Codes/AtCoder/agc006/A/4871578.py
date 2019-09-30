N=int(input())
s=input()
t=input()

ans = 2 * N
for i in reversed(range(0, N + 1)):
    if s[-i:] == t[:i]:
        ans = 2 * N - i
        break

print(ans)