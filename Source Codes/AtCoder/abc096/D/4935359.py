import sys
input = sys.stdin.readline

N = int(input())
upper = 55555
p_flag = [True]*(upper+1)
p_flag[0] = p_flag[1] = False
prime = []

for i in range(2, upper+1):
    if p_flag[i]:
        prime.append(i)
        for j in range(2*i, upper+1, i):
            p_flag[j] = False

ans = []
cnt = 0
for i in prime:
    if i % 5 == 1:
        ans.append(i)
        cnt += 1
    if cnt == N:
        break

print(*ans)