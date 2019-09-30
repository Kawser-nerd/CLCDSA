s = input()
tmp1 = list(s)
tmp2 = list(s)
tmp2.reverse()

res = 'YES'
for i in range(len(s)):
    if tmp1[i] != tmp2[i]:
        if tmp1[i] == '*' or tmp2[i] == '*':
            pass
        else:
            res = 'NO'
            break
            
print(res)