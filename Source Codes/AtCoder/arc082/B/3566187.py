def inpl(): return [int(i) for i in input().split()]

N =int(input())
p = inpl()
H = ''
for i in range(1,N+1):
    if i != p[i-1]:
        H += '1'
    else:
        H += '0'
H = H.replace('00','1')
ans = N - len(H)

ans += H.count('0')
print(ans)