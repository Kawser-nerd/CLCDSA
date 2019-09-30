S = input()
T = input()
list1 = {}
list2 = {}

flag = True
for i in range(len(S)):
    if S[i] in list1.keys():
        if list1[S[i]] != T[i]:
            flag = False
    if T[i] in list2.keys():
        if list2[T[i]] != S[i]:
            flag = False
    list1[S[i]] = T[i]
    list2[T[i]] = S[i]

if flag:
    print('Yes')
else:
    print('No')