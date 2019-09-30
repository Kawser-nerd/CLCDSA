S = input()
cc = 0
for i in range(len(S)-1):
  if S[i] != S[i + 1]:
    cc += 1
print(cc)