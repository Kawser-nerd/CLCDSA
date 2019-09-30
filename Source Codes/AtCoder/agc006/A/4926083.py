N = int(input())
s = input()
t = input()
for i in range(N):
    if s[i:] == t[:N-i]:
        print(N + i)
        break
else: print(2 * N)