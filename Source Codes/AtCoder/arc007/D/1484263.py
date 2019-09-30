import sys

S = input()
N = len(S)

if S [0] == '0':
    S = '1' + S

for i in range(len(S)):
    if i > 0 and S [i] != '0':
        ansA = int(S [:i])
        S = S [i:]
        break
else:
    ansA = int(S)
    S = ''

if len(S) == 0:
    print(ansA,1)
    sys.exit()

for i in range(1,5000):
    if i <= len(S):
        ansD = int(S [:i]) - ansA
        if ansD <= 0:
            continue
        prev = int(S [:i])
        if i == len(S):
            print(ansA,ansD)
            sys.exit()
        l = i
        r = i
        while True:
            if r <= len(S):
                if l != r and int(S [l:r]) > prev + ansD:
                    break
                elif l != r and int(S [l:r]) == prev + ansD:
                    prev += ansD
                    if r == len(S):
                        print(ansA,ansD)
                        sys.exit()
                    l = r
                    continue
            elif l != len(S) and S [l:] == str(prev + ansD) [:len(S) - l]:
                print(ansA,ansD)
                sys.exit()
            else:
                break
            r += 1
    else:
        if ansA < int(S + '0'):
            print(ansA,int(S + '0') - ansA)
            break
        elif ansA < int(S + '1'):
            print(ansA,int(S + '1') - ansA)
            break
        S = S + '0'