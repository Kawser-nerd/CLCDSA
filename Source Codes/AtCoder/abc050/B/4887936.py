I = lambda:map(int, input().split())
N = int(input())
T = list(I())
M = int(input())
ans = [sum(T)]*M
for i in range(M):
    p, x = I()
    ans[i] = ans[i] - T[p-1] + x
print('\n'.join(map(str, ans)))