def compute_score(s):
    return sum([(a - s)**2 for a in As])

N = int(input().strip())
As = list(map(int, input().strip().split()))

s = sum(As) / N
ans = 0
if(s % 1 == 0):
    ans = compute_score(s)
else:
    ans = min(compute_score(s // 1), compute_score(s // 1 + 1))
print(int(ans))