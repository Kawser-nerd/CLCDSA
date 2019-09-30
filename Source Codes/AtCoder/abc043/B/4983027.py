c = list(input())
ans = []
for i in range(len(c)):
    if c[i] == '0':
        ans.append('0')
    elif c[i] == '1':
        ans.append('1')
    elif len(ans) != 0:
        del ans[-1]
    else:
        continue

print (''.join(ans))