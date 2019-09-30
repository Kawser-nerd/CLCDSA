# 2019/04/14
# AtCoder Beginner Contest 116 - B

# Input
s = int(input())

# Init
sl = list()
lflg = True
sl.append(s)
cnt = 1

# Calc and Output
while(lflg):
    cnt += 1
    if s % 2 == 0:
        s = int(s / 2)
    else:
        s = 3 * s + 1

    for i in range(len(sl)):
        if s == sl[i]:
            print(cnt)
            lflg = False
            break
        
    sl.append(s)