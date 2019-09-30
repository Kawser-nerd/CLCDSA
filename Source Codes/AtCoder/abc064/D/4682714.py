N = int(input())
S = input()
unclosedBra = 0 #( num
unclosedKet = 0 #) num
for i in range(N):
  if S[i] == '(':
    unclosedBra += 1
  else:
    if unclosedBra > 0:
      unclosedBra -= 1
    else:
      unclosedKet += 1
ans = ('(' * unclosedKet ) + S + (')' * unclosedBra)
print(ans)