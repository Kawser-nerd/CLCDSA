n, a, b, c = map(int, input().split())
L = [int(input()) for _ in range(n)]
INF = 10**4

def search(cou, x, y, z):
    if cou == n:
        return abs(x-a) + abs(y-b) + abs(z-c) - 30 if min(x, y, z) > 0 else INF
    ret0 = search(cou+1, x, y, z)    
    ret1 = search(cou+1, x+L[cou], y, z) + 10
    ret2 = search(cou+1, x, y+L[cou], z) + 10
    ret3 = search(cou+1, x, y, z+L[cou]) + 10
    return min(ret0, ret1, ret2, ret3)

print(search(0, 0, 0, 0))