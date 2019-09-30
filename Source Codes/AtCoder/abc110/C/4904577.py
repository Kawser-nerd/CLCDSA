S = input()
T = input()
F = 1
DD = [0 for i in range(1001)]
NUM = [0 for i in range(1001)]
grid = [i for i in range(ord('a'),ord('z')+1)]
for i in range(len(S)):
    if (not DD[ord(S[i])] == ord(T[i])) and (not DD[ord(S[i])] == 0):
        F = 0
    if DD[ord(S[i])] == 0:
        NUM[ord(T[i])] = NUM[ord(T[i])] + 1
    DD[ord(S[i])] = ord(T[i])
for i in NUM:
    if i >= 2:
        F = 0
print("Yes" if F == 1 else "No")