N = int(input())
s = input()
t = input()
for i in range(N+1):
    if s[i:]==t[:N-i]:
        break
print(len(s+t[N-i:]))