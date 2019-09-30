S = input()
K = int(input())

n = -1
for i in range(len(S)):
    if S[i] != '1':
        n = i
        break
if n == -1:
    print(1)
elif K-1 < n:
    print(1)
else:
    print(S[n])