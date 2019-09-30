S = input()
while(True):
    S = S[:len(S)-1]
    if len(S) % 2 == 0:
        SA = S[:len(S)//2]
        SB = S[len(S)//2:]
        if SA == SB:
            print(len(S))
            break