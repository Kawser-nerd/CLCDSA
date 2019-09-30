N = int(input())
S = input()
l = len(S)
ans = []
for i in range(l-1):
    ans.append(len(set(S[0:i+1]) & set(S[i+1:l])))
print(max(ans))