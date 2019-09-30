N = int(input())
S = input()
a = []
first = 0
for k in range(1, N):
  if S[k] == 'E':
    first += 1

a.append(first)
for k in range(1, N):
  a.append(a[-1] + (S[k-1] == 'W') - (S[k] == 'E'))
print(min(a))