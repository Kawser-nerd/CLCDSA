S = input()

res = ''
for i in range(len(S)):
    if S[i].isdigit():
        res += S[i]
        
print(res)