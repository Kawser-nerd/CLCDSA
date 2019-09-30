from collections import defaultdict
N = int(input())

paper = defaultdict(int)
for i in range(N):
    A = int(input())
    paper[A] += 1

ans = 0
for k, v in paper.items():
    if v % 2 == 1:
        ans += 1
print(ans)