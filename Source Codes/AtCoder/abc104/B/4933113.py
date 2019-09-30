S = input()

countA = 0
countC = 0
for i in range(len(S)):
    if i == 0:
        if S[i] != 'A':
            print('WA')
            quit()
        else:
            countA += 1
            continue
    if S[i] == 'C':
        if i < 2 or i == len(S)-1:
            print('WA')
            quit()
        countC += 1
    elif not S[i].islower():
        print('WA')
        quit()
    if countA > 1 or countC > 1:
        print('WA')
        quit()

if countA != 1 or countC != 1:
    print('WA')
    quit()
print('AC')