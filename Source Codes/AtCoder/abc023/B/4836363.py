N = int(input())
S = input()

flag = True
if N%2 == 0:
    flag = False

c = int((N-1)/2) 
if S[c] != 'b':
    flag = False


for i in range(int((N-1)/2)):
    if i%3 == 1:
        if S[c-i] != 'a' or S[c+i] != 'c':
            flag=False
    if i%3 == 2:
        if S[c-i] != 'c' or S[c+i] != 'a':
            flag=False
    if i%3 == 0:
        if S[c-i] != 'b' or S[c+i] != 'b':
            flag=False

if flag:
    ans = (N-1)//2
else:
    ans = -1

print(ans)