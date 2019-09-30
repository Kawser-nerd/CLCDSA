prj = {}
prj_inv = {}
s = input()
t = input()
for i, j in zip(s, t):
    if i not in prj and j not in prj_inv:
        prj[i] = j
        prj_inv[j] = i
    elif i in prj and j in prj_inv:
        if prj[i] == j:
            continue
        else:
            print('No')
            break
    else:
        print('No')
        break
else:
    print('Yes')