E = set(map(int,input().split()))
B = int(input())
L = set(map(int,input().split()))
EL = E&L
if len(EL) == 6:
    ans = 1
elif len(EL) == 5:
    k = E - EL
    j = L - EL 
    if k == {B} or j == {B}:
        ans = 2
    else:
        ans = 3
elif len(EL) == 4:
    ans = 4
elif len(EL) == 3 :
    ans = 5
else:
    ans = 0
print(ans)