name = input()

tmp1 = list(name)
tmp2 = list(name)
tmp2.reverse()

res = 'YES'
for i in range(len(tmp1)):
    if tmp1[i] != tmp2[i]:
        res = 'NO'
        break
        
print(res)