s = input()
s += "?"
for i in range(len(s)-2):
    if len(set(list(s[i:i+3]))) < 3:
        if i == len(s)-3:
            print(i+1,i+2)
        else:
            print(i+1, i+3)
        exit()
print(-1, -1)