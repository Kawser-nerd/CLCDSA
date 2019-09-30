N = int(input())
S = input()
a = 0
b = 0
sub = 0
for i in range(N):
  if S[i] == '(':
    a += 1
  else:
    b += 1
  if a-b <= sub:
    sub = a-b
S = '('*max((-sub),0)+S+')'*max(a-b-sub,0)
print(S)