S=input()
d=10**4
for i in range(len(S)-2):
  dd=abs(753-int(S[i:i+3]))
  d=min(d,dd)
print(d)