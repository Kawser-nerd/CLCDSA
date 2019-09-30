s = input()
char = [s[0]]
num = []
count = 1
for i in range(1,len(s)):
    if s[i-1] == s[i]:
        count += 1
    else:
        num.append(count)
        count = 1
        char.append(s[i])
num.append(count)
print(''.join([ ch + str(nu) for ch, nu in zip(char, num)]))