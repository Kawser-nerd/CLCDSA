# coding: utf-8
# Your code here!

S = input()
sl = list(S)
ans = 0
for i in range(1 << len(S)): # ??(1,2,4,8...)
    string = str(0)
    tmp = 0
    for j in range(len(S)):
        if ((i >> j) & 1) == 1: # j,j+1?????+??
            tmp+=int(string)
            string = "0"
        else:
            string += str(S[j])
    tmp=tmp+int(string)
    ans+=tmp
print(ans)