A, B = map(int, input().split())
S = input()
ans = 'Yes'
if S[:A].isdecimal() == 0\
or S[A:A+1] != '-'\
or S[A+1:].isdecimal() == 0:
    ans = 'No'
print(ans)