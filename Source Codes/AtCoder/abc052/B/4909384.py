x = 0
N = int(input())
S = input()
ans = []
ans.append(x)
for i in range(N):
    if S[i] == "I":
        x += 1
    else:
        x -= 1
    ans.append(x)
print(max(ans))