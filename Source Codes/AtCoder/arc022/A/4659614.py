S = [str(_).upper() for _ in input()]
N = len(S)
flag = False

for i in range(N):
    if S[i] == "I":
        flag = True
        break
if flag:
    flag = False
    for j in range(i+1, N):
        if S[j] == "C":
            flag = True
            break
if flag:
    flag = False
    for k in range(j+1, N):
        if S[k] == "T":
            flag = True
            break
    
print("YES" if flag else "NO")