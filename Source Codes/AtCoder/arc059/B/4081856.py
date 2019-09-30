S = input()
one = S[0]
two = S[1]
ans = "-1 -1"
l = len(S)
for i in range(2,l):
    s = S[i]
    if s == one:
        ans = str(i-1) + " " + str(i+1)
        break
    elif s == two:
        ans = str(i) + " " + str(i+1)
        break
    one, two = two, s
if l == 2:
    if one == two:
        ans = "1 2"
print( ans)