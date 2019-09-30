S = [i for i in input()]
k = int(input())
anslist = []
for i in range(len(S)-k+1):
      anslist.append("".join(S[i:i+k]))
print(len(set(anslist)))