S = input()
dif = []
for i in range(len(S)-2):
    dif.append(abs(753 - int(S[i:i+3])))
print(min(dif))