h, w = map(int, input().split())

arr = []
exist = []

for i in range(h):
    s = input()
    a = []
    f = 0
    for j in range(w):
        if s[j] == '#':
            a.append(1)
            f = 1
        else:
            a.append(0)
    arr.append(a)
    if f == 1:
        exist.append(1)
    else:
        exist.append(0)
    
red = [[0 for i in range(w)] for j in range(h)]
blue = [[0 for i in range(w)] for j in range(h)]

flag = 0 #0????????????
pre_non_exist = 0
for i in range(h):
    if i == 0:
        for j in range(w):
            red[i][j] = 1
        flag = 1
    elif exist[i] == 1 and flag == 1:
        pre_non_exist = 0
        for j in range(w):
            blue[i][j] = 1
            if arr[i][j] == 1:
                red[i][j] = 1
        flag = 0
    elif exist[i] == 1 and flag == 0:
        pre_non_exist = 0
        for j in range(w):
            red[i][j] = 1
            if arr[i][j] == 1:
                blue[i][j] = 1
        flag = 1
    else:
        if pre_non_exist == 0:
            flag = (flag + 1) % 2
        pre_non_exist = 1
        if flag == 0:
            for j in range(w):
                if j == 0 or j == w-1:
                    red[i][j] = 1
                else:
                    blue[i][j] = 1
        else:
            for j in range(w):
                if j == 0 or j == w-1:
                    blue[i][j] = 1
                else:
                    red[i][j] = 1
                    
                    
for i in range(h):
    s = ""
    for j in range(w):
        if red[i][j] == 1:
            s = s + '#'
        else:
            s = s + '.'
    print(s)

print()

for i in range(h):
    s = ""
    for j in range(w):
        if blue[i][j] == 1:
            s = s + '#'
        else:
            s = s + '.'
    print(s)