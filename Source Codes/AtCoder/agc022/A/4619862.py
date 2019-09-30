S = input()

alph = [0] * 26

for index, i in enumerate(S):
    pointer = ord(i) - ord("a")
    alph[pointer] += 1


if(len(S) == 26):
    if(S=="zyxwvutsrqponmlkjihgfedcba"):
        print(-1)
        exit()
    else:
        old=""
        for i, s1 in enumerate(S[::-1]):
            if i != 0 and s1 < old[-1]:
                out = S[:len(S)-i-1] + min([o for o in old if o > s1])
                print(out)
                exit()
            old += s1
        
else:
    for i in range(26):
        if(alph[i]==0):
            print(S+chr(i+ord("a")))
            exit()