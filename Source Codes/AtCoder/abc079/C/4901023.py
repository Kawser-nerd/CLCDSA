S = [int(x) for x in list(input())]

for i in range(8):
    ch = S[0]
    for j in range(3):
        if int(i/(2**j)) % 2 == 0:
            ch += S[j+1]
        else:
            ch -= S[j+1]
    if ch == 7:
        print(S[0],end='')
        for j in range(3):
            if int(i/(2**j)) % 2 == 0:
                print('+',end='')
            else:
                print('-',end='')
            print(S[j+1],end='')
        print('=7')
        break