N, L = map(int, input().split())
S = input()

tmp = 1
res = 0
for i in range(len(S)):
    if S[i] == '+':
        tmp += 1
    else:
        tmp -= 1
    
    if tmp > L:
        tmp = 1
        res += 1
        
print(res)