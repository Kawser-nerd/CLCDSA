n, q = map(int, input().split())
s = input()
lr = [list(map(int, input().split())) for i in range(q)]

# 0-index
for i in range(q):
    for j in range(2):
        lr[i][j] -= 1

# 'AC'?????????
ac_cnt = [0 for i in range(n)]
for i in range(n-1):
    ac_cnt[i+1] = ac_cnt[i] + (1 if s[i:i+2] == 'AC' else 0)

for i in range(q):
    print(ac_cnt[lr[i][1]] - ac_cnt[lr[i][0]])