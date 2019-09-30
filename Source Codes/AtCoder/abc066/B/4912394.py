S = input()
if len(S) % 2 == 1:
    S = S[:-1]
else:
    S = S[:-2]
while True:
    if S[0 : int(len(S) / 2)] == S[int(len(S) / 2) : len(S)]:
        print(len(S))
        break
    else:
        S = S[:-2]