# coding: utf-8
# Your code here!
S = input()
ans = 0
for i in range(1 << len(S)): # ??(1,2,4,8...)
    string = str(0)
    tmp = 0
    enzan = []
    for j in range(len(S)):
        if ((i >> j) & 1) == 1:
            tmp+=int(S[j])
            enzan.append("+")
        else:
            tmp -= int(S[j])
            enzan.append("-")
    #print(tmp)
    if tmp == 7:
        #print(enzan)
        print(S[0]+enzan[1]+S[1]+enzan[2]+S[2]+enzan[3]+S[3]+"=7")
        exit()