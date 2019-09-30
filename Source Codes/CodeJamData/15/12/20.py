import sys
sys.stdin = open('a.in', 'r')
sys.stdout = open('a.out', 'w')




def getline():
    return [int(c) for c in input().split()]



def can(t, b, B, N):
    ans = 0
    flag = True
    count = sum([(t+(c-1))//c for c in b])
    free = sum([1 for c in b if t % c == 0])
    if count+free >= N:
        flag = True
        tmp = 0
        for j in range(B):
            if t % b[j] == 0:
                tmp += 1
            if tmp == N-count:
                return [j+1, True]
        return [0, True]
    else:
        return [0, False]

def solve():
    [B, N] = getline()
    b = getline()
    l = 0
    r = 10000000000000000
    [ans, flag] = can(l, b, B, N)
    if flag: return ans
    while l+1<r:
        m = (l+r) // 2
        [ans, flag] = can(m, b, B, N)
        if flag:
            r = m
        else:
            l = m
    [ans, flag] = can(r, b, B, N)
    #print(r)
    #print(can(27, b, B, N))
    return ans

    


for T in range(int(input())):
    sys.stderr.write(str(T))
    print('Case #%d: %s' % (T+1, solve()))