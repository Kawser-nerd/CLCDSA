N = int(input())

N -= 1
S = input()
recoder = []
recoder.append(S)
flag = True
S_tail = S[-1]

for i in range(N-1):
    S = input()
    S_head = S[0]
    if S_tail != S_head or S in recoder and flag:
        if i % 2 != 0:
           print("LOSE")
        else:
            print("WIN")
        flag = False
        break
    else:
        S_tail = S[-1]
        recoder.append(S)
if flag == True:
    print("DRAW")