Ss = [i for i in input()]
chars = []
char = [Ss[0]]
for s in range(1,len(Ss)):
    if Ss[s] in char:
        char.append(Ss[s])
    else:
        chars.append(char)
        char = [Ss[s]]
chars.append(char)
ans = [char[0]+str(len(char)) for char in chars]
print("".join(ans))