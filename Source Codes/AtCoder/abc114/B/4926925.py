S = str(input())
M = 753
min = 10000
for i in range(len(S)-2):
    a = 100*int(S[i]) + 10*int(S[i+1]) + int(S[i+2])
    b = abs(a - M)
    if b < min:
        min  = b

print(min)