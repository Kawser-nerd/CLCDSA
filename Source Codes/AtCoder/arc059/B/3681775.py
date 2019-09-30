S = input()

for i in range(len(S)-1):
    a,b = S[i],S[i+1]
    if a == b:
        print(i+1, i+2)
        exit()

for i in range(len(S)-2):
    a,b = S[i],S[i+2]
    if a == b:
        print(i+1, i+3)
        exit()

print(-1, -1)