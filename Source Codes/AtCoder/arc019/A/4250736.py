S = str(input())
S = list(S)
for i in range(len(S)):
    if S[i] == "O" or S[i] == "D":
        S[i] = '0'
    elif S[i] == "I":
        S[i] = '1'
    elif S[i] == "Z":
        S[i] = '2'
    elif S[i] == "S":
        S[i] = '5'
    elif S[i] == "B":
        S[i] = '8'
#print(S)
ans = ""
for i in range(len(S)):
    ans += S[i]
print(ans)