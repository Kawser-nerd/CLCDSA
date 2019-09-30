N = int(input())
fn = [list(map(int,input().split())) for _ in range(N)]
pn = [list(map(int,input().split())) for _ in range(N)]
bitf = []
for i in range(N):
    temp = 0
    for j in range(10):
        temp += ((2 ** j) * fn[i][j])
    bitf.append(temp)
#print(bitf)
def func(x , y):
    return bin(x & y).count('1')
ans = (-1) * 10 ** 10
for i in range(1,2**10):
    temp = 0
    for j in range(N):
        temp += pn[j][func(i,bitf[j])]
    ans = max(ans , temp)
print(ans)