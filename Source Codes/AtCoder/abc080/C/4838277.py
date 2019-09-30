import itertools

n = int(input())
f = [list(map(int,input().split())) for i in range(n)]
p = [list(map(int,input().split())) for i in range(n)]

ans = -float("inf")
for pattern in itertools.product(range(2), repeat=10):
  if sum(pattern)==0:
    continue

  tmp_ans = 0
  for mise_i in range(n):
    tmp_cnt = 0
    for i,ptn in enumerate(pattern):
      if ptn == 1 and f[mise_i][i] == 1:
        tmp_cnt += 1
    tmp_ans += p[mise_i][tmp_cnt]
  if tmp_ans > ans:
    ans = tmp_ans
print(ans)