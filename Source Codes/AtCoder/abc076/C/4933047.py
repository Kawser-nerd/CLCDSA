input_A = input()
input_T = input()
input_A, input_T = list(input_A), list(input_T)

if len(input_A) >= len(input_T):
    for i in range(len(input_A)-len(input_T), -1, -1):
        clear_flg = True
        for j in range(len(input_T)):
            if not (input_A[i + j] == '?' or input_A[i + j] == input_T[j]):
                clear_flg = False
                break

        if clear_flg is True:
            input_A[i:i + len(input_T)] = input_T
            input_A = ''.join(input_A).replace('?', 'a')
            break
else:
    clear_flg = False

if clear_flg is True:
    print(input_A)
else:
    print('UNRESTORABLE')