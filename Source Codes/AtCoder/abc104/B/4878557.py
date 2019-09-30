S = input()

ans = 0

for i in S:
  if str.islower(i):
    ans += 1

s = S[2:len(S)-1]

if S[0] == 'A' and s.count('C') == 1 and ans == len(S)-2:
  print('AC')
else:
  print('WA')