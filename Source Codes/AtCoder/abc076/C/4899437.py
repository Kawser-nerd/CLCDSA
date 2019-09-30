S = input()
T = input()

last = -1
for i in range(len(S)-len(T)+1):
    for j in range(len(T)):
        if S[i+j] is T[j] or S[i+j] is '?':
            if j == len(T)-1:
                last = i
        else:
            break
if last != -1:
    S = S[:last] + T + S[last+len(T):]
    S = S.replace('?', 'a')
    print(S)
    exit()

print('UNRESTORABLE')