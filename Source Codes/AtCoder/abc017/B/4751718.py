s = list(input())
i = 0
while i < len(s):
    if s[i] == "c":
        if s[i+1] != 'h':
            print("NO")
            break
        i += 2
    elif s[i] in 'oku':
        i += 1
    else:
        print("NO")
        break
    if i == len(s):
        print("YES")