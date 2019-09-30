N = input()
S = input()
st1 = []
st2 = []
tmp = ''
for x in S:
    if x == '(':
        st1.append(S)
    elif x == ')':
        if len(st1) > 0:
            st1.pop()
        else:
            tmp = '(' + tmp
    tmp += x
ans = tmp
for x in tmp[::-1]:
    if x == ')':
        st2.append(S)
    elif x == '(':
        if len(st2) > 0:
            st2.pop()
        else:
            ans += ')'
print(ans)