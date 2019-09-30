# ??????????????????
N, R = map(int, input().split(" "))
S = list(input())

while (S) and S[-1] == "o":
    S.pop()
    N -= 1

p = 0
cost = 0
for i in range(N):
    if S[i] != ".":
        continue
    S[i:i+R] = ["o"]*R
    # print(S)
    p = i
    cost += 1

# print(cost, p, N-R)
cost += min(max(0, N-R), p)
print(cost)