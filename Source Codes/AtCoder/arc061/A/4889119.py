S = input()
addition = 0
for i in range(2 ** (len(S)-1)):
    a = ''.join([c + ('+' if j < len(S)-1 and (i & 2 ** j == 2 ** j) else '') for j, c in enumerate(S)])
    for k in a.split('+'):
        addition += int(k)
print(addition)