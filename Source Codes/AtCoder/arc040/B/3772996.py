N, R = map(int, input().split())
S = input()
move = 0
if S.rfind(".") != -1:
    move = S.rfind(".") - R + 1
else:
    pass
if move <= 0:
    move = 0
c = 0
ban = 0
while S[c:].find('.') != -1:
    if S[c:].find('.') == -1:
        break
    else:
        c += S[c:].find('.') + R 
        ban += 1
print(ban + move)