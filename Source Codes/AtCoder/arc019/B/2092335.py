S = input()
L = len(S)
cnt = 0
for i in range((L+1)//2):
    if S[i] != S[-i-1]:
        cnt += 1
if cnt > 1:
    print(25*L)
elif cnt == 1:
    print(25*(L-2)+24*2)
else:
    if L % 2 == 1:
        print(25*(L-1))
    else:
        print(25*L)