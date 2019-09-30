import string
S = input()
A = string.ascii_lowercase
ans = list(set(A) - set(S))
ans.sort()
if ans == []:
    print('None')
else:
    print(ans[0])