N = int(input())
S = input()
S += S[0]

def roop(St):
    for i in range(1,N+1):
        flag = 1
        if S[i] == 'x':
            flag *= -1
        if St[i] == 'W':
            flag *= -1
        if St[i-1] == 'W':
            flag *= -1
        if flag == 1:
            St += 'S'
        else:
            St += 'W'
    return St
ans = '-1'
candidate = ('SS','WS','SW','WW')
for i in candidate:
    a = roop(i)
    if a[0] == a[-2] and a[1] == a[-1] :
        ans = a[0:N]
        break
print(ans)