s = [input() for i in range(3)]
flg = 1
while(True):
    if flg == 1:
        if s[0] == '':
            print('A')
            break
        elif s[0][0] == 'a':
            s[0] = s[0][1:]
            flg = 1
        elif s[0][0] == 'b':
            s[0] = s[0][1:]
            flg = 2
        elif s[0][0] == 'c':
            s[0] = s[0][1:]
            flg = 3
        
    elif flg == 2:
        if s[1] == '':
            print('B')
            break
        elif s[1][0] == 'a':
            s[1] = s[1][1:]
            flg = 1
        elif s[1][0] == 'b':
            s[1] = s[1][1:]
            flg = 2
        elif s[1][0] == 'c':
            s[1] = s[1][1:]
            flg = 3

    elif flg == 3:
        if s[2] == '':
            print('C')
            break
        elif s[2][0] == 'a':
            s[2] = s[2][1:]
            flg = 1
        elif s[2][0] == 'b':
            s[2] = s[2][1:]
            flg = 2
        elif s[2][0] == 'c':
            s[2] = s[2][1:]
            flg = 3