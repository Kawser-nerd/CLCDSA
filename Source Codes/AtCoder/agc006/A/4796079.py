N = int(input())
s = input()
t = input()
dup = 0
for i in range(N):
  if s[N-i-1:] == t[:i+1]:
    dup = i+1

print(2*N-dup)